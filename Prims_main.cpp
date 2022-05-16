#include <bits/stdc++.h>
using namespace std;

class graph
{
    int nv, ne;
    int** matrix;
    int* mst;
    int s, d, flag;
    int totalCost=0;
    vector<pair<int,int>> edgeList;
public:

    void buildMatrix()
    {
        cout<<"Enter number of vertexes: ";
        cin>>nv;
        cout<<"Enter number of Edges: ";
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
        cout<<"\nEnter The First, Second Node and Weight of the EDGES: \n";
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

    void Prims()
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
            totalCost=matrix[s][d];
            edge++;
        }
    }

    void displayList()
    {
        if(edgeList.size()<(nv-1))
        {
            cout<<"\n\t----GRAPH IS NOT CONNECTED----\n";
            return;
        }
        cout<<"\nEDGES present in MST(First Second Weight):\n";
        for(int i=0;i<nv-1;i++)
        {
            s=edgeList[i].first;
            d=edgeList[i].second;
            cout<<s<<"  "<<d<<"  "<<matrix[s][d]<<endl;
        }

        cout<<"TOTAL COST: "<<totalCost<<endl;
    }

} ;


int main()
{
    graph Gph;
    Gph.buildMatrix();
    Gph.Prims();
    Gph.displayList();
    return 0;
}
