#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <numeric>
#include <utility>
#include <iomanip>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <sstream>
#include <fstream>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	long long n,m,t,v,x,y,q;
	long long a[100004];
	int upd[1000004];
	long long sum[100004];
	scanf("%I64d%I64d",&n,&m);
	for (int i=0;i<n;i++)
	{
		scanf("%I64d",&a[i]);
		upd[i]=0;
	}
	sum[0]=0;
	for (int i=1;i<=m;i++)
	{
		scanf("%I64d",&t);
		if (t==1)
		{
			scanf("%I64d%I64d",&v,&x);
			a[v-1] = x;
			sum[i]=sum[i-1];
			upd[v-1]=i;
		}
		else if (t==2)
		{
			scanf("%I64d",&y);
			sum[i]=sum[i-1]+y;
		}
		else 
		{
			scanf("%I64d",&q);
			sum[i]=sum[i-1];
			q--;
			a[q] = sum[i]-sum[upd[q]]+a[q];
			upd[q]=i;
			printf("%I64d\n",a[q]);
		}
	}
    return 0;
}