/*
ID: wangyil2
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <stdio.h>

using namespace std;

int main() {
	ofstream fout ("gift1.out");
	ifstream fin ("gift1.in");
	map<string,int> names;
	string name[10];
	int cnt[10];
	int np;
	fin>>np;
	for (int i=0;i<np;i++)
	{
		string tmp;
		fin>>tmp;
		name[i]=tmp;
		names[tmp]=i;
		cnt[i]=0;
	}
	for (int i=0;i<np;i++)
	{
		string tmp;
		fin>>tmp;
		int num=names[tmp];
		int am,ng;
		fin>>am>>ng;
		if (ng!=0)
		{
			int giveout=am/ng;
			int remain=am%ng;
			cnt[num]-=am-remain;
			for (int j=0;j<ng;j++)
			{
				fin>>tmp;
				num=names[tmp];
				cnt[num]+=giveout;
			}
		}
	}
	for (int i=0;i<np;i++)
	{
		fout<<name[i]<<' '<<cnt[i]<<endl;
	}

}