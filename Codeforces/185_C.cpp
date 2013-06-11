#include <iostream>
#include <stdio.h>
#include <list>
#include <map>
#include <queue>
#include <cstring>
using namespace std;
int main()
{
	long long n,k;
	cin>>n>>k;
	if (n*(n-1)/2<=k)
		cout<<"no solution"<<endl;
	else 
	{
		for (int i=0;i<n;i++)
		{
			cout<<0<<' '<<i<<endl;
		}
	}

	return 0;
}