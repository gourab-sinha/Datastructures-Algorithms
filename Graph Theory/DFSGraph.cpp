#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void DFS(int** edges, int V, int sv, bool* visited)
{
    cout<<sv<<endl;
    visited[sv] = true;
    for(ll i=0;i<V;i++)
    {
        if(i!=sv)
        {
            if(edges[sv][i] && !visited[i])
            {
                DFS(edges,V,i,visited);
            }
        }
    }

}

int main()
{
    int V,e;
    cin>>V>>e;
    int **edges = new int*[V];
    for(ll i=0;i<V;i++)
    {
        edges[i] = new int[V];
        for(int j=0;j<V;j++)
        {
            edges[i][j] = 0;
        }
    }
    ll f,s;
    for(ll i=1;i<=e;i++)
    {
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    bool* visited = new bool[V];
    memset(visited,false,sizeof(visited));
    print(edges, n, 0, visited);
    delete [] edges;
    delete [] visited;
}
