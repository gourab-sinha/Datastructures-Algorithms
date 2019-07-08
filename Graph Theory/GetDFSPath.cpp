#include <bits/stdc++.h>
using namespace std;
vector<int> DFSPath(int** edges,int V,int tempX,int tempY,bool* visited,vector<int> path)
{
    if(tempX==tempY)
    {
        //path.push_back(tempX);
        path.push_back(tempY);
        return path;
    }
    visited[tempX] = true;
    for(int i=0;i<V;i++)
    {
        if(i!=tempX)
        {
            if(edges[tempX][i] && !visited[i])
            {
                //cout<<tempX<<endl;
                path = DFSPath(edges,V,i,tempY,visited,path);
                if(path.size())
                {
                    path.push_back(tempX);
                    return path;
                }
                    
            }
        }
    }
    path.clear();
    return path;
}

int main()
{
    int V, E, tempX, tempY;
    cin >> V >> E;
    int** edges = new int*[V];
    for(int i=0;i<V;i++)
    {
        edges[i]=new int[V];
        for(int j=0;j<V;j++)
        {
            edges[i][j] = 0;
        }
    }
    for(int i=0;i<E;i++)
    {
        cin>>tempX>>tempY;
        edges[tempX][tempY] = edges[tempY][tempX] = 1;
    }
    cin>>tempX>>tempY;
    vector<int> path,result;
    bool* visited = new bool[V];
    result = DFSPath(edges,V,tempX,tempY,visited,path);
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
    }
  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to Print the output yourself
	 
  */

  return 0;
}
