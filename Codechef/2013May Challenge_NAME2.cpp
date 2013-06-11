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
bool subSeq(const char *s, const char *p,int &len1,int &len2)
{
	int i = 0;
	int j = 0;
	while(i<len1)
	{
		if (s[i]==p[j])
		{
			i++;
			j++;
		}
		else i++;

		if (j==len2)
			return true;
	}
	return false;
}
int main()
{
	int T,N;
	char M[200005],W[200005];
	scanf("%d",&T);
	for (int i=0;i<T;i++)
	{
		scanf("%s%s",M,W);
		int len1 = strlen(M);
		int len2 = strlen(W);
		bool flag;
		if (len1>len2)
			flag = subSeq(M,W,len1,len2);
		else flag = subSeq(W,M,len2,len1);
		if (flag)
			printf("YES\n");
		else printf("NO\n");
		
	}
	return 0;
}