#include <iostream>
#include <algorithm>
using namespace std;
int num[100005];
int cmp(const void * l1,const void *l2)
{
	int * e1=(int *)l1;
	int * e2=(int *)l2;
	return (*e1)<(*e2);
}
int main()
{
	long long n,m;
	cin>>n>>m;
	for (int i=0;i<m;i++)
	{
		cin>>num[i];
		if (num[i]==1)
			m--;
	}
	long long sum = m *(n-m);
	cout<<sum<<endl;
	return 0;
}