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
	int cnt1[26],cnt2[26];
	char S[1005];
	cin>>T;
	while(T--)
	{
		cin>>S;
		int len = strlen(S);
		memset(cnt1,0,sizeof(cnt1));
		memset(cnt2,0,sizeof(cnt2));
		int first,second;
		if (len%2==0)
		{
			first = len/2;
			second = first;
		}
		else
		{
			first = len/2;
			second = first+1;
		}
		for (int i=0;i<first;i++)
		{
			cnt1[S[i]-'a']++;
		}
		for (int i=second;i<len;i++)
		{
			cnt2[S[i]-'a']++;
		}
		bool flag = true;
		for (int i=0;i<26;i++)
		{
			if (cnt1[i]!=cnt2[i])
			{
				flag = false;
				break;
			}
		}
		if (flag)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}