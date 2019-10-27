#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Triplet
{
	public:
		int x;
		int y;
		int gcd;
};

Triplet ExtendedEuclids(ll a,ll b)
{
	//Base case
	if(b==0)
	{
		Triplet smallAns;
		smallAns.x = 1;
		smallAns.y = 0;
		smallAns.gcd = a;
		return smallAns;
	}

	Triplet smallAns = ExtendedEuclids(b,a%b);

	Triplet ans;
	ans.x = smallAns.y;
	ans.y = smallAns.x - (a/b)*smallAns.y;
	ans.gcd = smallAns.gcd;
	return ans;
}
int main()
{
	ll a,b;
	cin >> a >> b;
	
	Triplet ans = ExtendedEuclids(a,b);
	cout << ans.x << endl << ans.y << endl << ans.gcd <<endl;
}