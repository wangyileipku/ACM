#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <list>
#include <algorithm>
#include <queue>
#include <stdlib.h>
using namespace std;
int M = 1000000007;
long long p[105],q[105],l[105];
long long M0,M1,A0,B0,C0,A1,B1,C1;
long long power(long long x, long long n)
{
	long long ans = 1;
	while(n)
	{
		if (n%2)
			ans = (ans*x)%M;
		x = (x*x)%M;
		n/=2;
	}
	return ans;
}
int main()
{
	int T;
	long long V,N;
	scanf("%d",&T);
	for (int i=0;i<T;i++)
	{
		scanf("%lld%lld",&V,&N);
		V%=M;
		scanf("%lld%lld%lld%lld%lld%lld",&p[0],&p[1],&A0,&B0,&C0,&M0);
		scanf("%lld%lld%lld%lld%lld%lld",&q[0],&q[1],&A1,&B1,&C1,&M1);
		for (int j=2;j<N;j++)
		{
			p[j] = (A0*A0)%M0;
			p[j] = (p[j]*p[j-1])%M0;
			p[j] = (p[j]+(B0*p[j-2])%M0)%M0;
			p[j] = (p[j]+C0)%M0;

			q[j] = (A1*A1)%M1;
			q[j] = (q[j]*q[j-1])%M1;
			q[j] = (q[j]+(B1*q[j-2])%M1)%M1;
			q[j] = (q[j]+C1)%M1;
		}
		long long ans = 1;
		bool flag = false;
		for (int j=0;j<N;j++)
		{
			l[j] = (p[j]*M1 + q[j]);
			if (V==0 && l[j]==0)
			{
				flag = true;
				break;
			}
			l[j] = (p[j]*M1 + q[j])%(M-1);
			ans = (ans*l[j])%(M-1);	
		}
		if (V==0)
		{
			if (flag)
				printf("1\n");
			else printf("0\n");
		}
		else
		{
			ans = power(V,ans);
			printf("%lld\n",ans);
		}
	}
	return 0;
}