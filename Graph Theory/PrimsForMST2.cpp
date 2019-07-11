#include <bits/stdc++.h>
using namespace std;
class Edges
{
    public:
        int parent;
        int weight;
};
//Counter is for number of edges in Minimum Spanning Tree
int counter = 0;
void PrimsForMST(int** graph,Edges* edges,bool* visited,int start,int V)
{
    visited[start] = true;
    for(int i=0;i<V;i++)
    {
        if(start!=i)
        {
            if(graph[start][i] && !visited[i])
            {
                if(graph[start][i]<edges[i].weight)
                {
                    edges[i].parent = start;
                    edges[i].weight = graph[start][i];
                }
            }
        }
    }
    counter++;
}
int FindNodeWithLessWeight(Edges* edges,bool* visited,int V)
{
    int minValue = INT_MAX;
    int start;
    for(int i=0;i<V;i++)
    {
        if(!visited[i] && edges[i].weight<minValue)
        {
            start = i;
            minValue = edges[i].weight;
        }
    }
    return start;
}
int main()
{
    int V, E, v1, v2, w;
    cin >> V >> E;
    bool *visited = new bool[V];
    memset(visited,false,sizeof(visited));
    int** graph = new int*[V];
    for(int i=0;i<V;i++)
    {
        graph[i] = new int[V];
        for(int j=0;j<V;j++)
        {
            graph[i][j] = 0;
        }
    }
    for(int i=0;i<E;i++)
    {
        cin>>v1>>v2>>w;
        graph[v1][v2] = graph[v2][v1] = w;
    }
    Edges* edges = new Edges[V];
    for(int i=0;i<V;i++)
    {
        edges[i].parent = -1;
        edges[i].weight = INT_MAX;
    }
    int start = 0;
    edges[start].weight = 0;
    while(1)
    {
        PrimsForMST(graph,edges,visited,start,V);
        start = FindNodeWithLessWeight(edges,visited,V);
        if(counter==V-1)
            break;
    }
    for(int i=0;i<V;i++)
    {
        if(edges[i].parent!=-1)
        {
            if(i<edges[i].parent)
            {
                cout<<i<<" "<<edges[i].parent<<" "<<edges[i].weight<<endl;
            }
            else
            {
                cout<<edges[i].parent<<" "<<i<<" "<<edges[i].weight<<endl;
            }
        }
    }
    delete [] edges;
    delete [] visited;
    delete [] graph;

  return 0;
}
