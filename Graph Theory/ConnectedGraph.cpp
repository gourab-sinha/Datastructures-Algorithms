#include <iostream>
using namespace std;
void ConnectedGraph(int** edges,int V,int sv,bool* visited)
{
    visited[sv] = true;
    for(int i = 0; i<V;i++)
    {
        if(sv!=i)
        {
            if(edges[sv][i] && !visited[i])
            {
                ConnectedGraph(edges,V,i,visited);
            }
        }
    }
}
int main() {
    int V, E;
    cin >> V >> E;
    int** edges = new int*[V];
    for(int i=0;i<V;i++)
    {
        edges[i] = new int[V];
        for(int j=0;j<V;j++)
        {
            edges[i][j] = 0;
        }
    }
    int sv,ev;
    for(int i=0;i<E;i++)
    {
        cin>>sv>>ev;
        edges[sv][ev] = edges[ev][sv] = 1;
    }
    bool* visited = new bool[V];
    ConnectedGraph(edges,V,0,visited);
    bool flag = true;
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            flag = false;
        }
    }
    delete [] edges;
    delete [] visited;
    cout<<(flag ? "true" : "false");
    
  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to take input and print the output yourself
	 
  */

  return 0;
}
