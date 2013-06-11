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
const int MAXN = 10005;
long long D[MAXN];
long long L[MAXN][2];
long long R[MAXN][2];
long long mL[MAXN][2];
long long mR[MAXN][2];
int main()
{
	int T,N;
	cin>>T;
	while(T--)
	{
		cin>>N;
		for (int i=0;i<N;i++)
		{
			cin>>D[i];
		}
		for (int i=0;i<N;i++)
		{
			if (i==0)
			{
				L[i][0] = D[i];
				L[i][1] = D[i];
				mL[i][0] = D[i];
				mL[i][1] = D[i];
			}
			else
			{
				if (L[i-1][0]<0)
					L[i][0] = L[i-1][0]+D[i];
				else L[i][0] = D[i];
				if (L[i-1][1]>0)
					L[i][1] = L[i-1][1]+D[i];
				else L[i][1] = D[i];

				mL[i][0] = L[i-1][0]<L[i][0]?L[i-1][0]:L[i][0];
				mL[i][1] = L[i-1][1]>L[i][1]?L[i-1][1]:L[i][1];
			}
		}
		for (int i=N-1;i>=0;i--)
		{
			if (i==N-1)
			{
				R[i][0] = D[i];
				R[i][1] = D[i];
				mR[i][0] = D[i];
				mR[i][1] = D[i];
			}
			else
			{
				if (R[i+1][0]<0)
					R[i][0] = R[i+1][0]+D[i];
				else R[i][0] = D[i];
				if (R[i+1][1]>0)
					R[i][1] = R[i+1][1]+D[i];
				else R[i][1] = D[i];

				mR[i][0] = R[i+1][0]<R[i][0]?R[i+1][0]:R[i][0];
				mR[i][1] = R[i+1][1]>R[i][1]?R[i+1][1]:R[i][1];
			}
		}
		long long ans = -1;
		for (int i=0;i<N-1;i++)
		{
			if (abs(mL[i][0]-mR[i+1][1])>ans)
				ans = abs(mL[i][0]-mR[i+1][1]);
			if (abs(mL[i][1]-mR[i+1][0])>ans)
				ans = abs(mL[i][1]-mR[i+1][0]);
		}
		cout<<ans<<endl;
	}
	return 0;
}