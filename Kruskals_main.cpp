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

class Graph
{
public:
    int nv, ne;
    int *parent;
    priority_queue<Edge> pe;
    priority_queue<Edge> opt;

    void createGraph()
    {
        cout<<"Enter Number Of Vertex: ";
        cin>>nv;
        cout<<"Enter Number Of Edges: ";
        cin>>ne;

        for(int i=0; i<ne; i++)
        {
            int f,s,w;
            cout<<"Enter The First, Second Node and Weight of the EDGE: ";
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
        parent = new int[nv];

        for(i=0; i<nv; i++)
            parent[i]=-1;

        i=0;
        while(i<nv-1 && !pe.empty())
        {
            Edge ed = pe.top();
            cout<<"\t"<<ed.weight<<"  "<<ed.fst<<"  "<<ed.scd<<endl;
            pe.pop();

            int p1 = findParent(ed.fst);
            int p2 = findParent(ed.scd);

            if(p1 != p2)
            {
                parent[p1] = p2; // Union Function
                i++;
                opt.push(ed);
            }
        }

        while (!pe.empty())  // To print the remaining input graph
        {
            Edge ed = pe.top();
            cout<<"\t"<<ed.weight<<"  "<<ed.fst<<"  "<<ed.scd<<endl;
            pe.pop();
        }

        if(opt.size() < (nv-1))
        {
            cout<<"\n\n==>> GRAPH NOT CONNECTED\n";
            return;
        }

        displayOutput();
    }

    void displayOutput()
    {
        cout<<"\n -----OUTPUT MST-----\n";
        while (!opt.empty())
        {
            Edge ed = opt.top();
            cout<<"\t"<<ed.weight<<"  "<<ed.fst<<"  "<<ed.scd<<endl;
            opt.pop();
        }
    }

};

int main()
{
    Graph Gp;
    Gp.createGraph();
    cout<<"\n -----INPUT GRAPH-----\n";
    Gp.kruskalMST();
    return 0;
}
