/*
ID: wangyil2
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int leap(int year)
{
	if (year % 100 ==0)
	{
		if (year % 400 == 0)
			return 1;
		else return 0;
	}
	else if (year % 4 == 0)
		return 1;
	else return 0;
}
int main() 
{
	int N;
	ofstream fout ("friday.out");
	ifstream fin ("friday.in");
	fin>>N;
	int res[7];
	memset(res,0,sizeof(res));

	int day = 0;
	for (int i=0;i<N;i++)
	{
		int year = 1900+i;
		for (int j=0;j<12;j++)
		{
			res[day]++;
			if (j == 1)
				day+=leap(year);
			day+=days[j];
			day %= 7;
		}
	}

	fout<<res[0];
	for (int i=1;i<7;i++)
		fout<<' '<<res[i];
	fout<<endl;
	return 0;

}