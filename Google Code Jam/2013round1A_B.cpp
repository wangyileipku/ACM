#include <iostream>
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
using namespace std;

int main()
{
	int v[10005];
	int next[10005];
	int T;
	int E,R,N;
	scanf("%d",&T);
	for (int cs=1;cs<=T;cs++)
	{
		memset(next,0,sizeof(next));
		scanf("%d%d%d",&E,&R,&N);
		for (int i=0;i<N;i++)
		{
			scanf("%d",&v[i]);
		}
		if(R>=E)
		{
			long long ans = 0;
			for(int i=0;i<N;i++)
				ans+=v[i];
			ans*=E;
			printf("Case #%d: %lld\n",cs,ans);
		}
		else
		{
			int maxcnt = E/R;
			v[N]=10000008;
			for (int i=0;i<N;i++)
			{
				next[i]=N<i+maxcnt?N:i+maxcnt;
				for (int j=i+1;j<=(N<i+maxcnt?N:i+maxcnt);j++)
				{
					if (v[i]<=v[j])
					{
						next[i]=j;
						break;
					}
				}
						//cout<<i<<' '<<next[i]<<endl;
			}

			long long ans = 0;
			int rest = E;
			for (int i=0;i<N;)
			{
				long long tmp;
				if (next[i]==N || v[next[i]]<v[i])
				{
					tmp = rest;
					ans += v[i]*tmp;
					rest = R;
					i++;
				}
				else if (E>(next[i]-i)*R+rest)
				{
					rest += (next[i]-i)*R;
					i=next[i];				
				}
				else
				{
					tmp= rest+(next[i]-i)*R-E;
					ans += v[i]*tmp;
					rest = E;
					i = next[i];
				}

				//cout<<ans<<endl;
			}
			printf("Case #%d: %lld\n",cs,ans);
		}

	}
	return 0;
}