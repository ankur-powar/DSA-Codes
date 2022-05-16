#include <bits/stdc++.h>
using namespace std;

class graph
{
    int nvertex;
    int nedges;
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

        cout<<"Enter the EDGES: \n";
        for(int i=0; i<nedges; i++)
        {
            int x,y;
            cin>>x>>y;

            matrix[x][y]=1;
            matrix[y][x]=1;
        }
    }

    void displayMatrix()
    {
        cout<<"\n    ----MATRIX----\n\n";
        for(int i=0; i<nvertex; i++)
        {
            for(int j=0; j<nvertex; j++)
            {
                cout<<matrix[i][j]<<"  ";
            }
            cout<<endl;
        }
    }

    void StartBFS()
    {
        vector<bool> check(nvertex, false);
        queue<int> q;
        int first = 0;
        q.push(first);

        check[first] = true;
        cout<<"\nBFS: ";

        while(!q.empty())
        {
            int current = q.front();
            q.pop();

            cout<<current<<" ";

            for(int i = 1; i < nvertex; i++)
            {
                if(matrix[current][i] && !check[i])
                {
                    q.push(i);
                    check[i] = true;
                }
            }
        }
    }

    void StartDFS()
    {
        vector<bool> check(nvertex, false);
        int cnt=0;
        for(int i=0; i<nvertex; i++)
        {
            if(!check[i])
            {
                cout<<"\nDFS: ";
                DFS(check, i);
                cnt++;
            }
        }
        cout<<"\nNumber Of Connected Components: "<<cnt<<endl;

    }

    void DFS(vector<bool> &vec, int idx)
    {
        vec[idx] = true;
        cout<<idx<<" ";
        for(int i=1; i<nvertex; i++)
        {
            if(matrix[idx][i] && !vec[i])
                DFS(vec, i);
        }
    }
};

int main()
{
    graph gr;
    gr.buildMatrix();
    gr.displayMatrix();
    gr.StartBFS();
    cout<<endl;
    gr.StartDFS();
    return 0;
}
