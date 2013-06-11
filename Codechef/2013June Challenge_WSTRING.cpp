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
int cummax1[10005];
int cummax2[10005];
int curmax[10005];
char S[10005];
int curcnt[26];
int cumcnt[26];
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		cin>>S;
		int len = strlen(S);
		memset(cumcnt,0,sizeof(cumcnt));
		memset(curcnt,0,sizeof(curcnt));
		int cnt = 0;
		for (int i=0;i<len;i++)
		{
			if (S[i]!='#')
			{
				cumcnt[S[i]-'a']++;
				curcnt[S[i]-'a']++;
			}
			else
			{
				int tmpcum = -1,tmpcur = -1;
				for (int j=0;j<26;j++)
				{
					if (cumcnt[j]>tmpcum)
						tmpcum = cumcnt[j];
					if (curcnt[j]>tmpcur)
						tmpcur = curcnt[j];
				}
				cummax1[cnt]=tmpcum;
				curmax[cnt]=tmpcur;				
				memset(curcnt,0,sizeof(curcnt));
				cnt++;
			}
		}
		memset(cumcnt,0,sizeof(cumcnt));
		int pos = cnt-1;
		for (int i=len-1;i>=0;i--)
		{
			if (S[i]!='#')
			{
				cumcnt[S[i]-'a']++;
			}
			else
			{
				int tmpcum = -1;
				for (int j=0;j<26;j++)
				{
					if (cumcnt[j]>tmpcum)
						tmpcum = cumcnt[j];
				}
				cummax2[pos]=tmpcum;
				pos--;
			}
		}

		int ans = 0;
		for (int i=0;i<cnt-2;i++)
		{
			if (cummax1[i]!=0 && curmax[i+1]!=0 && curmax[i+2]!=0 && cummax2[i+2]!=0)
			{
				int tmp = cummax1[i] + curmax[i+1] + curmax[i+2] + cummax2[i+2] + 3;
				if (tmp>ans)
					ans = tmp;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}