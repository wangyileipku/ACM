#include <iostream>
#include <stdio.h>
#include <list>
#include <queue>
using namespace std;

int d[10005];
int l[10005];
int D;
bool f[10005];
int len[10005];

int main()
{
	int t;
	int n;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		for (int j=0;j<10005;j++)
		{
			f[j]=false;
			len[j]=-1;
		}
		
		cin>>n;
		for (int j=0;j<n;j++)
			cin>>d[j]>>l[j];
		cin>>D;
		queue<int> que;
		f[0]=true;
		len[0]=d[0];
		que.push(0);
		bool flag=false;
		while(!que.empty())
		{
			int cur=que.front();
			que.pop();
			if (d[cur]+len[cur]>=D)
			{
				flag=true;
				break;
			}
			for (int j=cur+1;j<n;j++)
			{				
				if (len[j]==-1 && d[j]-d[cur]<=len[cur])
				{
					//cout<<d[j]<<d[cur]<<len[cur];
					len[j]=l[j]<d[j]-d[cur]?l[j]:d[j]-d[cur];
					que.push(j);
				}
				if (d[j]-d[cur]>len[cur])
					break;
			}
		}
		printf("Case #%d: ",i);
		if (flag)
			printf("YES\n");
		else

			printf("NO\n");
		
	}
	return 0;
}
