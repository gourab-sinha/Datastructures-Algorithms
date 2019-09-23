#include<bits/stdc++.h>
using namespace std;

bool Bipartite(vector<int>* edges,int n)
{
	unordered_set<int>* sets = new unordered_set<int>[2];
	vector<int> pending;
	pending.push_back(0);
	sets[0].insert(0);
	while(pending.size()>0)
	{
		int current = pending.back();
		pending.pop_back();
		int currset = sets[0].count(current)>0 ? 0 : 1;
		for(int i=0;i<edges[current].size();i++)
		{
			int neighbour = edges[current][i];
			if(sets[0].count(neighbour)==0 && sets[1].count(neighbour)==0)
			{
				sets[1-currset].insert(neighbour);
				pending.push_back(neighbour);
			}
			else if(sets[currset].count(neighbour)>0)
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	int n,e;
	cin>>n>>e;
	vector<int>* edges = new vector<int>[n];
	int f,s;
	for(int i=0;i<n;i++)
	{
		cin>>f>>s;
		edges[f-1].push_back(s-1);
		edges[s-1].push_back(f-1);
	}
	if(Bipartite(edges,n))
	{
		cout<<"Bipartite\n";
	}
	else
	{
		cout<<"Not a Bipartite\n";
	}
}