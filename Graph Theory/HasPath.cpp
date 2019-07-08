#include <bits/stdc++.h>
using namespace std;

bool BFSHasPath(int** edges,int V,int v1,int v2,bool* visited)
{
    queue<int> q;
    q.push(v1);
    visited[v1] = true;
    while(!q.empty())
    {
        int var = q.front();
        if(v2==var)
            return true;
        q.pop();
        //cout<<var<<" ";
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(edges[var][i])
                {
                    q.push(i);
                    visited[i] = true;
                }
                
            }
        }
    }
    return false;
}
int main() {
    int V, E;
    cin >> V >> E;
    int** edges = new int*[V];
    bool *visited = new bool[V];
    for(int i=0;i<V;i++)
    {
        visited[i] = false;
        edges[i] = new int[V];
        for(int j=0;j<V;j++)
        {
            edges[i][j] = 0;
        }
    }
    int f,s;
    for(int i=1;i<=E;i++)
    {
        cin>>f>>s;
        edges[f][s] = edges[s][f] = 1;
    }
    int v1,v2;
    cin>>v1>>v2;
    if(BFSHasPath(edges,V,v1,v2,visited))
    {
        cout<<"true";
    }
    else
    {
        cout<<"false";
    }
    delete [] visited;
    delete [] edges;

  /*

       Write Your Code Here
       Complete the Rest of the Program
       You have to take input and print the output yourself
     
  */

  return 0;
}
