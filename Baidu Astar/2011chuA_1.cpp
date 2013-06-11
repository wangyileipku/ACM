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
	int n,m;
	cin>>n>>m;
	for (int i=0;i<m;i++)
		cin>>num[i];
	qsort(num,m,sizeof(int),cmp);
	long long cnt=0;
	long long sum=0;
	long long now;
	long long last;
	long long lastpos;
	long long cur = 0;
	sum += (num[m-1]-1) * m * m;
	for (int j=m-1;j>=0;)
	{
		last = cur;
		lastpos = j+1;
		cur =num[j];
		now = j+1;

		while(j>=0 && num[j] == cur)
		{
			j--;
		}
		sum += now * (j+1);
	}
	sum += now * (cur - last - 1) * lastpos;
	cout<<sum<<endl;
	return 0;


}