/*
ID: wangyil2
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdio.h>

using namespace std;

int main() {
	ofstream fout ("ride.out");
	ifstream fin ("ride.in");
	char a[10],b[10];
	fin >> a >> b;
	int lena=strlen(a);
	int lenb=strlen(b);
	long long num1=1;
	long long num2=1;
	for (int i=0;i<lena;i++)
	{
		num1*=(a[i]-'A'+1);
		num1 %= 47;
	}
	for (int i=0;i<lenb;i++)
	{
		num2*=(b[i]-'A'+1);
		num2 %= 47;
	}
	if (num1==num2)
		fout << "GO" << endl;
	else
		fout<<"STAY"<<endl;
	return 0;
}