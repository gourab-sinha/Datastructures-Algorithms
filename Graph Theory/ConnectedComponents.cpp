#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void DFS(vector<int>* edges,int start,unordered_set<int>* component,bool* visited)
{
	visited[start] = true;
	component->insert(start);
	for(int i=0;i<edges[start].size();i++)
	{
		int next = edges[start][i];
		if(!visited[next])
		{
			DFS(edges,next,component,visited);
		}
	}
}
unordered_set<unordered_set<int>*>* getComponets(vector<int>* edges,int n)
{
	bool* visited = new bool[n];
	for(int i=0;i<n;i++)
		visited[i] = false;
	unordered_set<unordered_set<int>*>* output= new unordered_set<unordered_set<int>*>();	
	for(int i=0;i<n;i++)
	{
		if(!visited[i])
		{
			unordered_set<int>* component = new unordered_set<int>();
			DFS(edges,i,component,visited);
			output->insert(component);
		}
	}
	return output;
}	
int main()
{
	int n,e;
	//vertices
	cin>>n;
	//Declaring a array of vector. Each array element will have vector of type int.
	vector<int>* edges = new vector<int>[n];
	//edges
	cin>>e;
	int f,s;
	for(int i=0;i<e;i++)
	{
		cin>>f>>s;
		edges[f-1].push_back(s-1); // vertex f is connected to s and vice versa
		edges[s-1].push_back(f-1);
	}
	unordered_set<unordered_set<int>*>* components = getComponets(edges,n); 
	unordered_set<unordered_set<int>*>::iterator it1 = components->begin();
	while(it1!=components->end())
	{
		unordered_set<int>* component = *it1;
		unordered_set<int>::iterator it2 = component->begin();
		while(it2!=component->end())
		{
			cout<<*it2+1<<" ";
			it2++;
		}
		cout<<endl;
		delete component;
		it1++;
	}
	delete components;
	delete [] edges;
}