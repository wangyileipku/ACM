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
	int n;
	long long a[200005];
	long long d,k;
	long long sum=0;
	bool del = false;
	int cnt = 0;
	scanf("%d%I64d",&n,&k);
	for (int i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
		if (i==1)
			d=0;
		else
		{
			if (!del)
				sum+=a[i-1]*(i-2-cnt);
			d = sum-(n-i)*a[i]*(i-1-cnt);
		}
		if (d<k)
		{
			printf("%d\n",i);
			del = true;
			cnt++;
		}
		else
			del = false;
	}
    return 0;
}