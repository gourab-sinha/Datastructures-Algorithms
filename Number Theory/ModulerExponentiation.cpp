#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll Power(ll x,ll n,ll m)
{
	if(x==0)
		return 0;
	if(n==0)
		return 1;
	if(n%2==0)
	{
		ll small = Power(x,n/2,m);
		return ((small%m)*(small%m))%m;
	}
	else
	{
		ll small = Power(x,n/2,m);
		return ((x%m)*(small%m)*(small%m))%m;
	}
}
int main()
{
	ll x,n,m;
	cin>>x>>n>>m;
	cout<<Power(x,n,m)<<endl;
}