#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int* getLPS(string pattern)
{
	int len = pattern.length();
	int* lps = new int[len];
	lps[0] = 0;
	int i = 1;
	int j = 0;
	while(i<len)
	{
		if(pattern[i] == pattern[j])
		{
			lps[i] = j+1;
			j++;
			i++;
		}
		else
		{
			if(j!=0)
			{
				j = lps[j-1]; 	
			}
			else
			{
				lps[i] = 0;
				i++; 
			}
			
		}
	}
	return lps;
}

bool KMPSearch(string text,string pattern)
{
	int lenText = text.length();
	int lenPattern = pattern.length();

	int i = 0;
	int j = 0;

	int* lps = getLPS(pattern);
	while(i<lenText && j<lenPattern)
	{
		if(text[i] == pattern[j])
		{
			i++;
			j++;
		}
		else
		{
			if(j!=0)
			{
				j = lps[j-1];
			}
			else
			{
				i++;
			}
		}
	}
	if(j == lenPattern)
		return true;
	return false;
}