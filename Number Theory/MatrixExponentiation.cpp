#include<bits/stdc++.h>
using namespace std;

void Multiply(int A[2][2],int M[2][2])
{
	int fValue = A[0][0]*M[0][0] + A[0][1]*M[1][0];
	int sValue = A[0][0]*M[0][1] + A[0][1]*M[1][1];
	int tValue = A[1][0]*M[0][0] + A[1][1]*M[1][0];
	int lValue = A[1][0]*M[0][1] + A[1][1]*M[1][1];
	A[0][0] = fValue;
	A[0][1] = sValue;
	A[1][0] = tValue;
	A[1][1] = lValue;
}

void MatrixExponentiation(int A[2][2],int n)
{
	if(n == 0 || n==1)
		return;
	MatrixExponentiation(A,n/2);
	Multiply(A,A);
	if(n%2)
	{
		int M[2][2] = {{1,1},{1,0}};
		Multiply(A,M);
	}
}

int Fib(int n)
{
	int A[2][2] = {{1,1},{1,0}};
	if(n==0)
		return 0;
	MatrixExponentiation(A,n-1);
	return A[0][0];
}

int main()
{
	int n;
	cin>>n;
	cout<<Fib(n)<<endl;
}