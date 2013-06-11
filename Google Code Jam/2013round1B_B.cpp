#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <cmath>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int f[20];
const int level = 20;
int cnt[level];
double p[2][level];
double C(int a,int b)
{
	return f[a]*1.0/f[b]/f[a-b];
}
int main()
{
	f[0]=1;
	for (int i=1;i<10;i++)
		f[i]=f[i-1]*i;
	for (int i=0;i<level;i++)
	{
		cnt[i]=4*i+1;
	}
	for (int i=1;i<level;i++)
	{
		cnt[i]=cnt[i]+cnt[i-1];
	}
	int T,N,X,Y;
	scanf("%d",&T);

	for (int cs=1;cs<=T;cs++)
	{
		scanf("%d%d%d",&N,&X,&Y);
		if (X<0)
			X=-X;
		int l = (X+Y)/2;
		if (l>3)
			printf("Case #%d: %.6lf\n",cs,0.0);
		else if (l==0)
			printf("Case #%d: %.6lf\n",cs,1.0);
		else if (N<=cnt[l-1])
			printf("Case #%d: %.6lf\n",cs,0.0);
		else if (N>=cnt[l])
			printf("Case #%d: %.6lf\n",cs,1.0);
		else if (X==0)
		{
			printf("Case #%d: %.6lf\n",cs,0.0);
		}
		else
		{
			N = N-cnt[l-1];
			if (N<=l*2)
			{
				p[0][0] = 1-C(N,N)/pow(2.0,N);
				for (int i=1;i<N;i++)
				{
					p[0][i] = p[0][i-1] - C(N,N-i)/pow(2.0,N);
				}
				printf("Case #%d: %.6lf\n",cs,p[0][Y]);
			}
			else
			{
				if (Y<N-l*2)
					printf("Case #%d: %.6lf\n",cs,1.0);
				else
				{
					int pos = N-l*2;
					double base = 1;
					for (int i=0;i<pos;i++)
						base  = base - C(N,N-i)/pow(2.0,N);

					p[0][pos] = base-C(N,N)/pow(2.0,N);
					for (int i=pos+1;i<N;i++)
					{
						p[0][i] = p[0][i-1] - C(N,N-i)/pow(2.0,N);
					}

					printf("Case #%d: %.6lf\n",cs,p[0][Y]/base);
				}
			}
		}
	}
	return 0;
}