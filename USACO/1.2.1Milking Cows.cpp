/*
ID: wangyil2
PROG: milk2
LANG: C++
*/
/*
Alg: Complete Search(Brute-force)
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <list>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
class MilkMan
{
public:
	int s;
	int e;
};
int cmp(const void *e1,const void *e2)
{
	MilkMan * l1=(MilkMan *)e1;
	MilkMan * l2=(MilkMan *)e2;
	return (l1->s)-(l2->s);
}
int main() 
{
	
	int N;
	MilkMan milk[5005];
	ofstream fout ("milk2.out");
	ifstream fin ("milk2.in");
	fin>>N;
	for (int i=0;i<N;i++)
		fin>>milk[i].s>>milk[i].e;
	qsort(milk,N,sizeof(MilkMan),cmp);

	int curstart = milk[0].s, curend=milk[0].e;
	int ans1 = milk[0].e-milk[0].s, ans2 = 0;
	for (int i=1;i<N;i++)
	{
		if (milk[i].s>curend)
		{
			if (curend-curstart > ans1)
				ans1=curend-curstart;
			if (milk[i].s-curend > ans2)
				ans2=milk[i].s-curend;
			curstart=milk[i].s;
			curend=milk[i].e;
		}
		else
			curend = milk[i].e>curend?milk[i].e:curend;
	}
	fout<<ans1<<' '<<ans2<<endl;


	return 0;

}