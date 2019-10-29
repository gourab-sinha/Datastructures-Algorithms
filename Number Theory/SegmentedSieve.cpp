#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define MAX 100001
vector<ll> getPrimes()
{
	bool* primes = new bool[MAX];
	for(ll i=0;i<MAX;i++)
		primes[i] = true;
	primes[0] = primes[1] = false;
	for(ll i=2;i*i<MAX;i++)
	{
		if(primes[i])
		{
			for(ll j = i*i; j<MAX; j+=i)
			{
				primes[j] = false;
			}
		}
	}
	vector<ll> primeNumbers;
	primeNumbers.push_back(2);
	for(ll i=3;i<MAX;i+=2)
	{
		if(primes[i])
			primeNumbers.push_back(i);
	}
	return primeNumbers;
}

void printPrimes(vector<ll>& primeNumbers,ll l,ll r)
{
	bool* primes = new bool[r-l+1];
	for(ll i=0;i<=r-l;i++)
		primes[i] = true;

	for(ll i=0;primeNumbers[i]*primeNumbers[i]<=r;i++)
	{
		ll currentPrime = primeNumbers[i];

		//To start we will need a base for that setting up base
		ll base = (l/currentPrime)*currentPrime;
		if(base<l)
		{
			base = base + currentPrime;
		}

		//Marking all the number false which are not prime
		for(ll j = base; j<=r;j+=currentPrime)
		{
			primes[j-l] = false;
		}

		//Reason there might be a case when base and currentPrime is same. Prime number we cannot make it false
		if(base == currentPrime)
			primes[base-l] = true;
	}
	for(ll i=0;i<=r-l;i++)
	{
		if(primes[i])
			cout<< l+i <<endl;
	}
}

int main()
{
	vector<ll> primeNumbers = getPrimes();
	ll t;
	cin>>t;
	while(t--)
	{
		ll l,r;
		cin>>l>>r;
		printPrimes(primeNumbers,l,r);
	}
}