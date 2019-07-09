#include <bits/stdc++.h>
using namespace std;

class Graph
{
    public:
        int source;
        int end;
        int weight;
};

//Compare weight of two graph objects;
bool compare(Graph g1, Graph g2)
{
    return g1.weight<g2.weight;
}

//find the grand of the child and return;
int findGrandParent(int child, int* parent)
{
    while(1)
    {
        if(child!=parent[child])
        {
            child = parent[child];
        }
        else
            break;
    }
    //will return grand parent;
    return child;
}

//Check whether we can add this edge to MST;
bool checkParent(Graph graph,int* parent)
{
    int grandParentA = findGrandParent(graph.source,parent);
    int grandParentB = findGrandParent(graph.end,parent);
    
    return grandParentA!=grandParentB ? true : false;
}

//Update parent after adding edge to MST
void updateParent(int* parent,int source,int end)
{
    int grandParentA = findGrandParent(source,parent);
    int grandParentB = findGrandParent(end,parent);
    parent[grandParentB] = grandParentA;
}

int main()
{
    int V, E, source, end, weight;
    cin >> V >> E;
    Graph* graph = new Graph[E];
    for(int i=0; i<E;i++)
    {
        cin>>source>>end>>weight;
        graph[i].source = source;
        graph[i].end = end;
        graph[i].weight = weight;
    }
    sort(graph,graph+E,compare);
    
    int* parent = new int[V];
    for(int i=0;i<V;i++)
    {
        parent[i] = i;
    }
    int counter=0;
    Graph *output = new Graph[V-1];
    for(int i=0;i<E;i++)
    {
        if(checkParent(graph[i],parent))
        {
            int A = graph[i].source;
            int B = graph[i].end;
            //In test case: v1 v2 w where v1<v2
            if(A<B)
            {
                output[counter].source = A;
                output[counter].end = B;    
            }
            else
            {
                output[counter].source = B;
                output[counter].end = A;    
            }
            output[counter].weight = graph[i].weight;
            updateParent(parent,graph[i].source,graph[i].end);
            counter++;
            
        }
        if(counter==V-1)
            break;
    }
    for(int i=0;i<V-1;i++)
    {
        cout<<output[i].source<<" "<<output[i].end<<" "<<output[i].weight<<endl;
    }

  return 0;
}
