#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void EulerTotient(ll n)
{
	ll* phi = new ll[n+1];
	for(ll i=0;i<=n;i++)
		phi[i] = i;
	for(ll i=2;i<=n;i++)
	{
		if(phi[i]==i)
		{
			phi[i] = i-1;
			for(ll j=2*i;j<=n;j+=i)
			{
				phi[j] = (phi[j]*(i-1))/i;
			}
		}
	}
	for(ll i=1;i<=n;i++)
		cout<<"Euler Totient Phi for "<<i<<" is "<<phi[i]<<endl;
}
int main()
{
	ll n;
	cin >> n;
	EulerTotient(n);
}