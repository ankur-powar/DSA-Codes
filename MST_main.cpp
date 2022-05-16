/*
                                3262 ANKUR POWAR
                            7. Minimum Spanning Tree
You have a business with several offices; you want to lease phone lines to
connect them up with each other; and the phone company charges different
amounts of money to connect different pairs of cities. You want a set of lines
that connects all your offices with a minimum total cost. Solve the problem by
suggesting appropriate data structures and using prim's and kruskal's algorithm.
*/

#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int fst, scd, weight;

    Edge(int a, int b, int w)
    {
        fst = a;
        scd = b;
        weight = w;
    }
};

bool operator<(const Edge& e1, const Edge& e2)
{
    return e1.weight > e2.weight;
}

class Kruskal
{
public:
    int nv, ne;
    int *parent;
    int MinimumCost;
    priority_queue<Edge> pe;
    priority_queue<Edge> opt;

    void createGraph()
    {
        cout<<"Enter Number Of Cities     : ";
        cin>>nv;
        cout<<"Enter Number Of Connections: ";
        cin>>ne;
        MinimumCost = 0;

        cout<<"Enter The First City, Second City and Cost of the Connection: \n";
        for(int i=0; i<ne; i++)
        {
            int f,s,w;
            cin>>f>>s>>w;
            Edge e(f,s,w);
            pe.push(e);
        }
    }

    int findParent(int x)
    {
        if(parent[x] == -1)
            return x;
        else
            findParent(parent[x]);
    }

    void kruskalMST()
    {
        int i;
        parent = new int[nv+1];

        for(i=0; i<=nv; i++)
            parent[i]=-1;

        i=0;
        cout<<"\n \t-----ALL CONNECTIONS-----\n";
        while(i<nv-1 && !pe.empty())
        {
            Edge ed = pe.top();
            cout<<"\t      "<<ed.fst<<"  "<<ed.scd<<" \t"<<ed.weight<<endl;
            pe.pop();

            int p1 = findParent(ed.fst);
            int p2 = findParent(ed.scd);

            if(p1 != p2)
            {
                parent[p1] = p2; // Union Function
                i++;
                opt.push(ed);
                MinimumCost += ed.weight;
            }
        }

        while (!pe.empty())  // To print the remaining input graph
        {
            Edge ed = pe.top();
            cout<<"\t      "<<ed.fst<<"  "<<ed.scd<<" \t"<<ed.weight<<endl;
            pe.pop();
        }

        if(opt.size() < (nv-1))
        {
            cout<<"\n\t----ALL CITIES ARE NOT CONNECTED----\n";
            return;
        }

        displayOutput();
    }

    void displayOutput()
    {
        cout<<"\n -----CONNECTED CITIES USING KRUSKAL ALGORITHM-----\n";
        cout<<"\t------F  S \t   WEIGHT-------\n";
        while (!opt.empty())
        {
            Edge ed = opt.top();
            cout<<"\t      "<<ed.fst<<"  "<<ed.scd<<" \t     "<<ed.weight<<endl;
            opt.pop();
        }

        cout<<"\n\tMINIMUM TOTAL COST = "<<MinimumCost<<endl;
    }

};

class Prims
{
    int nv, ne;
    int** matrix;
    int* mst;
    int s, d, flag;
    int MinimumCost=0;
    vector<pair<int,int>> edgeList;
public:

    void buildMatrix()
    {
        cout<<"Enter Number Of Cities     : ";
        cin>>nv;
        cout<<"Enter Number Of Connections: ";
        cin>>ne;

        matrix = new int*[nv+1];
        mst =  new int[nv+1];
        for (int i = 0; i <= nv; i++)
        {
            matrix[i] = new int[nv+1];
            for(int j=0; j<=nv; j++)
                matrix[i][j]=0;

            mst[i]=0;
        }

        int f,s,w;
        cout<<"\nEnter The First City, Second City and Cost of the Connection: \n";
        for(int i=0; i<ne; i++)
        {
            cin>>f>>s>>w;

            matrix[f][s]=w;
            matrix[s][f]=w;
        }
    }

    void findEdge()
    {
        int smallWeight = INT_MAX;
        flag=0;
        for(int i=1; i<=nv; i++)
        {
            if(mst[i])
            {
                for(int j=1; j<=nv; j++)
                {
                    if(!mst[j])
                    {
                        if(matrix[i][j]!=0 && matrix[i][j]<smallWeight)
                        {
                            smallWeight=matrix[i][j];
                            s=i;
                            d=j;
                            flag=1;
                        }
                    }
                }
            }
        }
    }

    void PrimsMST()
    {
        int edge=0;
        mst[1]=1;
        while(edge!=nv-1)
        {
            findEdge();
            if(flag==0)
                break;
            mst[d]=1;
            edgeList.push_back(make_pair(s,d));
            MinimumCost += matrix[s][d];
            edge++;
        }
        displayList();
    }

    void displayList()
    {
        if(edgeList.size()<(nv-1))
        {
            cout<<"\n\t----ALL CITIES ARE NOT CONNECTED----\n";
            return;
        }
        cout<<"\n -----CONNECTED CITIES USING PRIMS ALGORITHM-----\n";
        cout<<"\t--------F  S \t     WEIGHT-----------\n";
        for(int i=0;i<nv-1;i++)
        {
            s=edgeList[i].first;
            d=edgeList[i].second;
            cout<<"\t\t"<<s<<"  "<<d<<" \t     "<<matrix[s][d]<<endl;
        }

        cout<<"\n\tMINIMUM TOTAL COST = "<<MinimumCost<<endl;
    }

} ;


int main()
{
    while(true)
    {
        int choice;
        cout<<"\n\n-------------------------------------------\n";
        cout<<"-------------------MENU--------------------\n";
        cout<<"\t1] KRUSKALS ALGORITHM\n";
        cout<<"\t2] PRIMS ALGORITHM\n";
        cout<<"\t3] EXIT\n";
        cout<<"\tEnter Your Choice: ";
        cin>>choice;
        cout<<"\n";

        /* If-Else is used in place of Switch so that object's
            get destroyed after each iteration                */
        if(choice==1)
        {
            Kruskal Kgp;
            Kgp.createGraph();
            Kgp.kruskalMST();
        }
        else if(choice==2)
        {
            Prims Pgp;
            Pgp.buildMatrix();
            Pgp.PrimsMST();
        }
        else
        {
            cout<<"\t-------THANK YOU-------\n";
            return 0;
        }
    }
    return 0;
}
