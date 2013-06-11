#include <iostream>
#include <stdio.h>
#include <list>
#include <queue>
#include <map>
#include <cmath>
#include <algorithm>
#include <string>
#include <memory>

using namespace std;
double dis[1005][1005];
double x[1005];
double y[1005];
double z[1005];
double eps=1e-7;
double eps2=1e-10;
int n,k;
bool check(double m)
{
	list<int> remain;
	list<int>::iterator it;
	for (int i=0;i<n;i++)
		remain.push_back(i);
	bool flag=true;
	it=remain.begin();
	int cnt=0;
	while(flag)
	{
		flag=false;
		queue<int> que;
		que.push(*it);
		remain.erase(it);
		while(!que.empty())
		{
			int cur=que.front();
			que.pop();
			for (it=remain.begin();it!=remain.end();)
			{
				int i=*it;
				if (dis[cur][i]<m-eps2)
				{
					que.push(i);
					list<int>::iterator tmp=it;
					tmp++;
					remain.erase(it);
					it=tmp;
				}
				else it++;
			}
		}
		cnt++;
		if (remain.size()>0)
		{
			flag=true;
			it=remain.begin();
		}
		if (cnt>=k)
			return true;
	}
	//cout<<cnt<<endl;
	if (cnt>=k)
		return true;
	else return false;
}
double calc(int i,int j)
{
	double xx=x[i]-x[j];
	double yy=y[i]-y[j];
	double zz=z[i]-z[j];
	return (xx*xx+yy*yy+zz*zz);
}
int main()
{
	cin>>n>>k;
	for (int i=0;i<n;i++)
	{
		cin>>x[i]>>y[i]>>z[i];
	}
	double maxt=-1;
	for (int i=0;i<n;i++)
		for (int j=i+1;j<n;j++)
		{
			double d=calc(i,j);
			dis[i][j]=dis[j][i]=d;
			//cout<<d<<endl;
			if (d>maxt)
				maxt=d;
		}
	double l=0;
	double r=maxt;
	double m=(l+r)/2;
	while(l<r-eps)
	{
		if (check(m))
			l=m;
		else
			r=m;
		m=(l+r)/2;
		//cout<<m<<endl;
	}
	printf("%.6lf\n",m);
	return 0;
}
