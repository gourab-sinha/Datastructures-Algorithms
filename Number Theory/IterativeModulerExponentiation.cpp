#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll ModulerExponentiation(ll x,ll n,ll m)
{
	ll result = 1;
	while(n>0)
	{
		if(n&1)
		{
			result = (result%m * x%m)%m;
		}
		n /= 2;
		x  = (x*x)%m;
	}
	return result;
}
int main()
{
	ll x,n,m;
	cin>>x>>n>>m;
	cout<<ModulerExponentiation(x,n,m)<<endl;
}