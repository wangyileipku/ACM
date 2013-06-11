/*
ID: wangyil2
PROG: transform
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

int N;

bool same(char a[11][11], char b[11][11])
{
	for (int i=0;i<N;i++)
		for (int j=0;j<N;j++)
			if (a[i][j]!=b[i][j])
				return false;
	return true;
}

void Rotate(char src[11][11], char dest[11][11], int deg)
{
	for (int i=0;i<N;i++)
		for (int j=0;j<N;j++)
		{
			if (deg==1)
				dest[j][N-1-i]=src[i][j];
			else if (deg==2)
				dest[N-1-i][N-1-j]=src[i][j];
			else if (deg==3)
				dest[N-1-j][i]=src[i][j];
			else if (deg==4)
				dest[i][N-1-j]=src[i][j];
		}
}
void print(char m[11][11])
{
	for (int i=0;i<N;i++)
	{
		for (int j=0;j<N;j++)
			cout<<m[i][j];
		cout<<endl;
	}
	cout<<endl;
}
int main() 
{
	
	ofstream fout ("transform.out");
	ifstream fin ("transform.in");
	fin>>N;
	char before[11][11],after[11][11],trans[11][11],trans2[11][11];
	for (int i=0;i<N;i++)
		fin>>before[i];
	for (int i=0;i<N;i++)
		fin>>after[i];

	Rotate(before,trans,1);
	print(trans);
	if (same(after,trans))
	{
		fout<<1<<endl;
		return 0;
	}
	
	Rotate(before,trans,2);
	print(trans);
	if (same(after,trans))
	{
		fout<<2<<endl;
		return 0;
	}
	
	Rotate(before,trans,3);
	print(trans);
	if (same(after,trans))
	{
		fout<<3<<endl;
		return 0;
	}

	Rotate(before,trans,4);
	print(trans);
	if (same(after,trans))
	{
		fout<<4<<endl;
		return 0;
	}

	
	Rotate(trans,trans2,1);
	print(trans2);
	if (same(after,trans2))
	{
		fout<<5<<endl;
		return 0;
	}
	
	Rotate(trans,trans2,2);
	print(trans2);
	if (same(after,trans2))
	{
		fout<<5<<endl;
		return 0;
	}
	
	Rotate(trans,trans2,3);
	print(trans2);
	if (same(after,trans2))
	{
		fout<<5<<endl;
		return 0;
	}

	if (same(before,after))
	{
		fout<<6<<endl;
		return 0;
	}

	fout<<7<<endl;

	return 0;

}