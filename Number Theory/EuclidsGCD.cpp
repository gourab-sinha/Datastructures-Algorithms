#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll gcd(ll a,ll b)
{
	if(a<b)
		return gcd(b,a);
	if(b==0)
	{
		return a;
	}
	return gcd(b,a%b);
}
int main()
{
	ll a,b;
	cin >> a >> b;
	cout<<gcd(a,b)<<endl;
}