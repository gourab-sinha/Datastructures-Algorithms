#include <bits/stdc++.h>
using namespace std;

void ShortestPath(int** graph,int* pathDistance,bool* visited,int V,int start,int distance)
{
    visited[start] = true;
    for(int i=0;i<V;i++)
    {
        if(start!=i)
        {
            if(graph[start][i] && !visited[i])
            {
                if(graph[start][i] + distance <pathDistance[i])
                {
                    pathDistance[i] = graph[start][i] + distance;
                }
            }
        }
    }
}

int FindMinWeight(bool* visited,int* pathDistance,int V)
{
    int minValue = INT_MAX;
    int start;
    for(int i=0;i<V;i++)
    {
        if(!visited[i] && pathDistance[i]<minValue)
        {
            minValue = pathDistance[i];
            start = i;
        }
    }
    return start;
}

bool CheckAllVisited(bool* visited,int V)
{
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
            return false;
    }
    return true;
}
int main()
{
    int V, E, source, end, weight;
    cin >> V >> E;
    bool* visited = new bool[V];
    for(int i=0;i<V;i++)
    {
        visited[i] = false;
    }
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
        cin>>source>>end>>weight;
        graph[source][end] = graph[end][source] = weight;
    }
    
    int* pathDistance = new int[V];
    for(int i=0;i<V;i++)
    {
        pathDistance[i] = INT_MAX;
    }
    int start = 0;
    pathDistance[start] = 0;
    while(1)
    {
        ShortestPath(graph,pathDistance,visited,V,start,pathDistance[start]);
        start = FindMinWeight(visited,pathDistance,V);
        if(CheckAllVisited(visited,V))
        {
            break;
        }
    }
    for(int i=0;i<V;i++)
    {
        cout<<i<<" "<<pathDistance[i]<<endl;
    }
  return 0;
}
