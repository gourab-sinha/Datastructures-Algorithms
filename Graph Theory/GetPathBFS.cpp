#include <bits/stdc++.h>
using namespace std;

vector<int> GetPathBFS(int** edges,int V,int sv,int ev,bool* visited)
{
    queue<int> q;
    q.push(sv);
    visited[sv] = true;
    map<int,int> mp;
    bool flag=false;
    while(!q.empty())
    {
        int var = q.front();
        q.pop();
        for(int i=0;i<V;i++)
        {
            if(var!=i)
            {
                if(!visited[i] && edges[var][i])
                {
                    mp[i] = var;
                    q.push(i);
                    visited[i] = true;
                    if(ev == i)
                    {
                        flag = true;
                        break;
                    }   
                }
            }
        }
        if(flag)
            break;
    }
    vector<int> path;
    if(flag)
    {
        int var = ev;
        path.push_back(var);
        while(1)
        {
            path.push_back(mp[var]);
            var = mp[var];
            if(var==sv)
                break;
        }
        return path;
    }
    return path;


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
    vector<int> path;
    int sv,ev;
    cin>>sv>>ev;
    path = GetPathBFS(edges,V,sv,ev,visited);
    for(int i=0;i<path.size();i++)
    {
        cout<<path[i]<<" ";
    }
    delete [] visited;
    delete [] edges;

  return 0;
}
