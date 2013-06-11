#include <iostream>
#include <stdio.h>
#include <list>
#include <map>
#include <queue>
#include <cstring>
using namespace std;
int main()
{
	double a,b,c,d;
	cin>>a>>b>>c>>d;
	double p1 = a/b;
	double p2 = c/d;
	double q1 = 1 - p1;
	double q2 = 1 - p2;
	printf("%.10lf\n",p1/(1-q1*q2));

	return 0;
}