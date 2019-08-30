#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void BuildTree(int* a,int* seg,int start,int end,int index)
{
    if(start==end)
    {
        seg[index] = a[start];
        return;
    }
    int mid = start + (end-start)/2;
    BuildTree(a,seg,start,mid,2*index);
    BuildTree(a,seg,mid+1,end,2*index+1);
    seg[index] = min(seg[2*index],seg[2*index+1]);
}

void UpdateTree(int* seg,int* lazy,int start,int end,int index,int left,int right,int value)
{
    if(start>end)
        return;

    //Not in the range
    if(start>right || end<left)
        return;

    //Updating the seg tree and updating child of lazy tree.
    if(lazy[index]!=0)
    {
        seg[index] += lazy[index];
        if(start!=end)
        {
            lazy[2*index] += lazy[index];
            lazy[2*index+1] += lazy[index]; 
        }
        lazy[index]=0;
    }
    //Complete overlap;
    if(left<=start && end<=right)
    {
        seg[index] += value;
        if(start!=end)
        {
            lazy[2*index] += value;
            lazy[2*index+1] += value; 
        }
        return;
    }
    int mid = start + (end-start)/2;
    UpdateTree(seg,lazy,start,mid,2*index,left,right,value);
    UpdateTree(seg,lazy,mid+1,end,2*index+1,left,right,value);
    seg[index] = min(seg[2*index],seg[2*index+1]);
}

int QueryTree(int* seg,int* lazy,int start,int end,int index,int left,int right)
{
    if(start>right || end<left)
        return INT_MAX;
    if(lazy[index]!=0)
    {
        seg[index] += lazy[index];
        if(start!=end)
        {
            lazy[2*index] = lazy[2*index+1] = lazy[index];
        }
        lazy[index] = 0;
    }
    if(left<=start && end<=right)
    {
        return seg[index];
    }
    int mid = start + (end-start)/2;
    int leftside = QueryTree(seg,lazy,start,mid,2*index,left,right);
    int rightside = QueryTree(seg,lazy,mid+1,end,2*index+1,left,right);
    return min(leftside,rightside);
}
int main()
{
    int n;
    cin>>n;
    int* a = new int[n];
    int* seg = new int[4*n+1];
    int* lazy = new int[4*n+1];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<=4*n;i++)
        lazy[i] = 0;
    BuildTree(a,seg,0,n-1,1);
    int q,left,right,value,type;
    cin>>q;
    while(q--)
    {
        cin>>type;
        if(type)
        {
            cin>>left>>right>>value;
            UpdateTree(seg,lazy,0,n-1,1,left-1,right-1,value);
        }
        else
        {
            cin>>left>>right;
            cout<<QueryTree(seg,lazy,0,n-1,1,left-1,right-1)<<endl;
        }
    }
}