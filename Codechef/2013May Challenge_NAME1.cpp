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
	int T,N;
	int cnt[26];
	char A[200005],B[200005];
	scanf("%d",&T);
	for (int i=0;i<T;i++)
	{
		memset(cnt,0,sizeof(cnt));
		scanf("%s%s",A,B);
		scanf("%d",&N);
		int len = strlen(A);
		for (int j=0;j<len;j++)
		{
			cnt[A[j]-'a']++;
		}
		len = strlen(B);
		for (int j=0;j<len;j++)
		{
			cnt[B[j]-'a']++;
		}
		bool flag = true;
		for (int k=0;k<N;k++)
		{
			scanf("%s",A);
			if (flag)
			{
			len = strlen(A);
			for (int j=0;j<len;j++)
			{
				cnt[A[j]-'a']--;
				if (cnt[A[j]-'a']<0)
					flag = false;
			}
			}
		}
		if (flag)
			printf("YES\n");
		else printf("NO\n");
		
	}
	return 0;
}