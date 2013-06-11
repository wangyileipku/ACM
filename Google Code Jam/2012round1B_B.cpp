#include <iostream>
#include <stdio.h>
using namespace std;

int t,h,n,m;
int s=10;
int myceil[105][105];
int myfloor[105][105];
double mytime[105][105];
double large=10000000000;

int main()
{
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>h>>n>>m;
		for (int j=0;j<n;j++)
			for (int k=0;k<m;k++)
				cin>>myceil[j][k];
		for (int j=0;j<n;j++)
			for (int k=0;k<m;k++)
				cin>>myfloor[j][k];

		mytime[0][0]=0;
		bool flag=false;

		for (int j=1;j<n;j++)
		{
			if (flag)
			{
				mytime[j][0]=large;
				continue;
			}
			if (myceil[j][0]-myfloor[j][0]<50 || myceil[j][0]-myfloor[j-1][0]<50)
			{
				mytime[j][0]=large;
				flag=true;
				continue;
			}
			if (myceil[j][0]-(h-mytime[j-1][0]*10)>=50)
			{
				if (h-mytime[j-1][0]*10-myfloor[j-1][0]<=0)
					mytime[j][0]=mytime[j-1][0];

				else if (h-mytime[j-1][0]*10-myfloor[j-1][0]>=20)
					mytime[j][0]=mytime[j-1][0]+1;
				else
					mytime[j][0]=mytime[j-1][0]+10;
			}
			else
			{
				double tm=(h-(myceil[j][0]-50))*1.0/10;
				if (h-tm*10-myfloor[j-1][0]>=20)
					mytime[j][0]=tm+1;
				else
					mytime[j][0]=tm+10;
			}
		}
		flag=false;
		for (int j=1;j<m;j++)
		{
			if (flag)
			{
				mytime[0][j]=large;
				continue;
			}
			if (myceil[0][j]-myfloor[0][j]<50 || myceil[0][j]-myfloor[0][j-1]<50)
			{
				mytime[0][j]=large;
				flag=true;
				continue;
			}
			if (myceil[0][j]-(h-mytime[0][j-1]*10)>=50)
			{
				if (h-mytime[0][j-1]*10-myfloor[0][j-1]<=0)
					mytime[0][j]=mytime[0][j-1];
				else if (h-mytime[0][j-1]*10-myfloor[0][j-1]>=20)
					mytime[0][j]=mytime[0][j-1]+1;
				else
					mytime[0][j]=mytime[0][j-1]+10;
			}
			else
			{
				double tm=(h-(myceil[0][j]-50))*1.0/10;
				if (h-tm*10-myfloor[0][j-1]>=20)
					mytime[0][j]=tm+1;
				else
					mytime[0][j]=tm+10;
			}
		}

		for (int j=1;j<n;j++)
			for (int k=1;k<m;k++)
			{
				if (myceil[j][k]-myfloor[j][k]<50)
				{
					mytime[j][0]=large;
					continue;
				}
				double tmptm1=large;
				double tmptm2=large;
				if (myceil[j][k]-myfloor[j-1][k]>=50)
				{
					if (myceil[j][k]-(h-mytime[j-1][k]*10)>=50)
					{
						if (h-mytime[j-1][k]*10-myfloor[j-1][k]<=0)
							tmptm1=mytime[j-1][k];
						else if (h-mytime[j-1][k]*10-myfloor[j-1][k]>=20)
							tmptm1=mytime[j-1][k]+1;
						else
							tmptm1=mytime[j-1][k]+10;
					}
					else
					{
						double tm=(h-(myceil[j][k]-50))*1.0/10;
						if (h-tm*10-myfloor[j-1][k]>=20)
							tmptm1=tm+1;
						else
							tmptm1=tm+10;
					}
				}
				if (myceil[j][k]-myfloor[j][k-1]>=50)
				{
					if (myceil[j][k]-(h-mytime[j][k-1]*10)>=50)
					{
						if (h-mytime[j][k-1]*10-myfloor[j][k-1]<=0)
							tmptm2=mytime[j][k-1];
						else if (h-mytime[j][k-1]*10-myfloor[j][k-1]>=20)
							tmptm2=mytime[j][k-1]+1;
						else
							tmptm2=mytime[j][k-1]+10;
					}
					else
					{
						double tm=(h-(myceil[j][k]-50))*1.0/10;
						if (h-tm*10-myfloor[j][k-1]>=20)
							tmptm2=tm+1;
						else
							tmptm2=tm+10;
					}
				}
				mytime[j][k]=tmptm1<tmptm2?tmptm1:tmptm2;
			}


		printf("Case #%d: %.6f\n",i,mytime[n-1][m-1]);
		//cout<<"Case #"<<i<<": "<<mini<<endl;
	}
	return 0;
}