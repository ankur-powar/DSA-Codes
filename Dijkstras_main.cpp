#include <bits/stdc++.h>
using namespace std;

class graph
{
    int nvertex;
    int nedges;
    int source;
    int** matrix;

public:
    void buildMatrix()
    {
        cout<<"Enter number of vertexes: ";
        cin>>nvertex;
        cout<<"Enter number of Edges: ";
        cin>>nedges;

        matrix = new int*[nvertex];
        for (int i = 0; i < nvertex; i++)
        {
            matrix[i] = new int[nvertex];
            for(int j=0; j<nvertex; j++)
                matrix[i][j]=0;
        }

        cout<<"Enter the EDGES(first,second,weight): \n";
        for(int i=0; i<nedges; i++)
        {
            int x,y,w;
            cin>>x>>y>>w;
            matrix[x][y]=w;
            matrix[y][x]=w;
        }
        cout<<"\nEnter the source Vertex: ";
        cin>>source;
    }

    void dijikstraAlgo()
    {
        vector<int> dist(nvertex,INT_MAX);
        dist[source]=0;
        vector<bool> visited(nvertex,false);
        vector<int> parent(nvertex, 0);

        int addVertex = source;
        int minDist, minVert;

        for(int i=0;i<nvertex-1;i++)
        {
            minDist = INT_MAX;
            visited[addVertex]=true;
            for(int j=0;j<nvertex;j++)
            {
                if(!visited[j])
                {
                    if(matrix[addVertex][j] && dist[j] > (dist[addVertex]+matrix[addVertex][j]))
                    {
                        dist[j] = dist[addVertex]+matrix[addVertex][j];
                        parent[j]=addVertex;
                    }
                    if(dist[j] < minDist)
                    {
                        minDist = dist[j];
                        minVert = j;
                    }
                }
            }
            addVertex = minVert;
        }
        cout<<"\n----Shortest Distance and Path from Source to each Vertex----\n";
        cout<<"SOURCE    DESTINATION    DISTANCE      PATH\n";
        for(int i=0;i<nvertex;i++)
        {
            stack<int> path;
            int d=i;
            while(d!=source)
            {
                path.push(d);
                d=parent[d];
            }
            cout<<"  "<<source<<"\t\t"<<i<<"\t   "<<dist[i]<<"\t\t";
            cout<<source;
            while(!path.empty())
            {
                cout<<" -> "<<path.top();
                path.pop();
            }
            cout<<endl;
        }
    }
};

int main()
{
    graph ghp;
    ghp.buildMatrix();
    ghp.dijikstraAlgo();
    return 0;
}
