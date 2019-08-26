// 69335157220 
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void buildTree(int* a,int* SegTree,int start,int end,int index)
{
	if(start==end)
	{
		SegTree[index] = a[start];
		return;
	}
	int mid = start + (end-start)/2;
	buildTree(a,SegTree,start,mid,2*index);
	buildTree(a,SegTree,mid+1,end,2*index+1);
	SegTree[index] = SegTree[2*index]+SegTree[2*index+1];
}
void UpdateTree(int* a,int* SegTree,int start,int end,int index,int pos,int value)
{
	//
	if(start==end)
	{
		a[start] = value;
		SegTree[index] = value;
		return;
	}
	int mid = start + (end-start)/2;
	if(pos>mid)
	{
		UpdateTree(a,SegTree,mid+1,end,2*index+1,pos,value);
	}
	else
	{
		UpdateTree(a,SegTree,start,mid,2*index,pos,value);
	}
	SegTree[index] = SegTree[2*index] + SegTree[2*index+1];
}

int QueryTree(int* a,int* SegTree,int start,int end,int index,int left,int right)
{
	//outside the range
	if(end<left || right<start)
		return 0;
	if(start>=left && end<=right)
	{
		return SegTree[index];
	}
	
	int mid = start + (end-start)/2;
	int ans1 = QueryTree(a,SegTree,start,mid,2*index,left,right);
	int ans2 = QueryTree(a,SegTree,mid+1,end,2*index+1,left,right);
	return ans1+ans2;
	//completely inside the range

	//partialy inside the 
}
int main()
{
	int n;
	cin>>n;
	int* a = new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int* SegTree = new int[4*n+1];
	memset(SegTree,0,sizeof(SegTree));
	buildTree(a,SegTree,0,n-1,1);
	//UpdateTree(a,SegTree,0,n-1,1,2,10);
	
	// for(int i=1;i<=4*n;i++)
	// {
	// 	cout<<SegTree[i]<<" Index:"<<i<<endl;
	// }
	// cout<<endl;
	// for(int i=0;i<n;i++)
	// {
	// 	cout<<a[i]<<endl;
	// }
	int q;
	cin>>q;
	cout<<"Queries\n";
	while(q--)
	{
		int left,right;
		cin>>left>>right;
		cout<<QueryTree(a,SegTree,0,n-1,1,left,right)<<endl;
	}

}