#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void DFSExtended(vector<int>* edges,int start,bool* visited,stack<int>* finishVertex)
{
	visited[start] = true;
	for(int i=0;i<edges[start].size();i++)
	{
		int adjacent = edges[start][i];
		if(!visited[adjacent])
		{
			DFSExtended(edges,adjacent,visited,finishVertex);
		}
	}
	finishVertex->push(start);
}

void DFS(vector<int>* edgesT,int start,bool* visited,unordered_set<int>* component)
{
	visited[start] = true;
	component->insert(start);
	for(int i=0;i<edgesT[start].size();i++)
	{
		int adjacent = edgesT[start][i];
		if(!visited[adjacent])
		{
			DFS(edgesT,adjacent,visited,component);
		}
	}
}
unordered_set<unordered_set<int>*>* GetComponents(vector<int>* edges,vector<int>* edgesT,int v)
{
	bool* visited = new bool[v];
	stack<int>* finishVertex = new stack<int>();
	for(int i=0;i<v;i++)
		visited[i] = false;
	for(int i=0;i<v;i++)
	{
		if(!visited[i])
		{
			DFSExtended(edges,i,visited,finishVertex);
		}
	}
	for(int i=0;i<v;i++)
	{
		visited[i] = false;
	}
	unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();
	while(!finishVertex->empty())
	{
		int start = finishVertex->top();
		finishVertex->pop();
		if(!visited[start])
		{
			unordered_set<int>* component = new unordered_set<int>();
			DFS(edgesT,start,visited,component);
			output->insert(component);
		}
	}
	return output;

}
int main()
{
	int v,e,f,s;
	cin>>v>>e;
	vector<int>* edges = new vector<int>[v];
	vector<int>* edgesT = new vector<int>[v];
	for(int i=0;i<e;i++)
	{
		cin>>f>>s;
		edges[f-1].push_back(s-1);
		edgesT[s-1].push_back(f-1);
	}

	unordered_set<unordered_set<int>*>* components = GetComponents(edges,edgesT,v);
	unordered_set<unordered_set<int>*>::iterator it1 = components->begin();
	while(it1!= components->end())
	{
		unordered_set<int>* component = *it1;
		unordered_set<int>::iterator it2 = component->begin();
		while(it2!=component->end())
		{
			cout<<*it2+1<<" ";
			it2++;
		}
		//delete component;
		cout<<endl;
		it1++;
	}
	delete [] edgesT,edges;
	delete components;
}