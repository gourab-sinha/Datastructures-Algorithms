#include <bits/stdc++.h>
using namespace std;


void BFS(int** edges,int V,int sv,bool* visited)
{
    queue<int> q;
    q.push(sv);
    visited[sv] = true;
    while(!q.empty())
    {
        int var = q.front();
        q.pop();
        cout<<var<<" ";
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
}

void BFSDisconnectedGraph(int** edges,int V,bool* visited)
{
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            BFS(edges,V,i,visited);
        }
    }
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
    BFSDisconnectedGraph(edges,V,visited);
    //print(edges,V,0,visited);
    delete [] visited;
    delete [] edges;

  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to take input and print the output yourself
	 
  */

  return 0;
}
