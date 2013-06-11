/*
ID: wangyil2
PROG: beads
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

int main() 
{
	int N;
	char bead[770]="";
	ofstream fout ("beads.out");
	ifstream fin ("beads.in");
	fin>>N;
	fin>>bead;

	int res = -1;

	for (int i=0;i<N;i++)
	{
		int cnt1=0,cnt2=0;
		int cur = i;
		char curb=bead[cur];
		while(true)
		{
			cnt1++;
			cur++;
			cur=cur%N;
			if (cur == i)
				break;
			if (bead[cur]!=curb && bead[cur]!='w')
			{
				if (curb!='w')
					break;
				else curb=bead[cur];
			}
		}
		cur = i-1;
		cur = (cur+N)%N;
		curb=bead[cur];
		while(true)
		{
			cnt2++;
			cur--;
			cur=(cur+N)%N;
			if (cur == i)
				break;
			if (bead[cur]!=curb && bead[cur]!='w')
				break;
		}
		if(cnt1+cnt2>res)
		{
			res=cnt1+cnt2;
			//cout<<cnt1<<' '<<cnt2<<' '<<res<<' '<<i<<endl;
		}
	}
	if (res>N)
		res=N;
	fout<<res<<endl;
	return 0;

}