#include <iostream>
#include <stdio.h>
#include <list>
#include <map>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
int cmp(const void *e1, const void *e2)
{
	int *l1 = (int *)e1;
	int *l2 = (int *)e2;
	return (*l1)-(*l2);
}
int main()
{
	long long dp[100005][101];
	int last[100005][101];
	int n,m,p;
	int d[100005];
	int h,t;
	long long T[100005];
	scanf("%d%d%d",&n,&m,&p);
	d[1] = 0;
	for (int i=2;i<=n;i++)
	{
		scanf("%d",&d[i]);
		d[i] += d[i-1];
	}
	for (int i = 0;i<m;i++)
	{
		scanf("%d%d",&h,&t);
		T[i] = t - d[h];
	}
	if (m<=p)
		printf("0\n");
	else
	{
		qsort(T,m,sizeof(long long),cmp);
		dp[0][0] = 0;
		last[0][0] = -1;
		for (int i = 1;i<m;i++)
		{
			long long grow = T[i]-T[i-1];
			dp[i][0] = dp[i-1][0] + grow * i;
			last[i][0] = -1;
		}
		for (int i=1;i<p;i++)
		{
			for (int j = i;j<p;j++)
			{
				dp[i][j]=0;
				last[i][j] = i-1;
			}
		}
		for (int i = 1;i<m;i++)
		{
			for (int j = 1;j<min(i,p);j++)
			{
				long long a,b;
				long long grow = T[i] - T[i-1];
				a = dp[i-1][j] + grow * (i - last[i-1][j]-1);
				grow = T[i] - T[i-1];
				b = dp[i-1][j-1];
				if (a<b)
				{
					dp[i][j] = a;
					last[i][j] = last[i-1][j];
				}
				else
				{
					dp[i][j] = b;
					last[i][j] = i-1;
				}
			}
		}
		printf("%I64d\n",dp[m-1][p-1]);
	}

	return 0;
}