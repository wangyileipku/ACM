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

int x[1005],y[1005];
int a[2],b[2];
int k[2];
class Pair
{
public:
	int person;
	int present;
	int value;
};
Pair p[2500];
int cmp(const void * e1,const void * e2)
{
	Pair * l1=(Pair *)e1;
	Pair * l2=(Pair *)e2;
	return l2->value-l1->value;
}
int main()
{
	bool has[1005];
	int n;
	cin>>n;
	for (int i=0;i<n;i++)
	{
		cin>>x[i]>>y[i];
		has[i]=false;
	}
	for (int i=0;i<2;i++)
		cin>>k[i]>>a[i]>>b[i];
	int cnt=0;
	for (int i=0;i<n;i++)
		for (int j=0;j<2;j++)
		{
			p[cnt].person=i;
			p[cnt].present=j;
			p[cnt].value=x[i]*a[j]+y[i]*b[j];
			cnt++;
		}

		qsort(p,cnt,sizeof(Pair),cmp);
		long long sum=0;
		for (int i=0;i<cnt;i++)
		{
			if (!has[p[i].person]&&k[p[i].present]>0)
			{
				sum+=p[i].value;
				has[p[i].person]=true;
				k[p[i].present]--;
			}
		}
		cout<<sum<<endl;
		return 0;
}
