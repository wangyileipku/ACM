#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <list>
#include <algorithm>
#include <queue>
#include <stdlib.h>
using namespace std;
int main()
{
	int T;
	double p,x;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lf",&p);
		if (p>0.5)
			x = 10000;
		else x=0;
		printf("%.7lf\n",10000*(2*p+1)*(1-p)+(2*p-1)*x);
	}
	return 0;
}