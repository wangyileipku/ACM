#include <iostream>
using namespace std;
__int64 dis[1001];
__int64 dist[1001];
__int64 tt[1001];
int main()
{
	__int64 t,L,T,N,C;
	cin>>t;
	for (__int64 i=1;i<=t;i++)
	{
		cin>>L>>T>>N>>C;
		for (__int64 j=0;j<C;j++)
		{
			cin>>dis[j];
		}
		__int64 cnt=0;
		for (__int64 j=0;j<N;j++)
		{
			dist[j]=dis[cnt];
			cnt++;
			cnt=cnt%C;
		}
		__int64 ans=0;
		if (L==0)
		{
			for (__int64 j=0;j<N;j++)
			{
				ans+=dist[j];
			}
			ans*=2;
		}
		else if (L==1)
		{
			double realdis=T/2;
			__int64 sum=0;
			__int64 pos=N-1;
			for (__int64 j=0;j<N;j++)
			{				
				sum+=dist[j];
				if (sum>=realdis)
				{
					pos=j;
					break;
				}
			}
			__int64 mini=10000000000000000;
			for (__int64 j=0;j<N;j++)
			{
				ans+=dist[j];
				tt[j]=ans;
			}
			ans*=2;
			for (__int64 j=0;j<N;j++)
			{
				if (j<pos)
				{
					__int64 tempans=ans;
					mini=tempans<mini?tempans:mini;
				}
				else if (j>pos)
				{
					__int64 tempans=ans-dist[j];
					mini=tempans<mini?tempans:mini;
				}
				else 
				{
					__int64 tempans;
					if (j>0)
						tempans=ans-dist[j]+(T-tt[j-1])*0.5;
					else tempans=ans-dist[j]+(T)*0.5;
					mini=tempans<mini?tempans:mini;
				}
			}
			ans=mini;
		}
		else if (L==2)
		{
			double realdis=T/2;
			__int64 sum=0;
			__int64 pos=N-1;
			for (__int64 j=0;j<N;j++)
			{				
				sum+=dist[j];
				if (sum>=realdis)
				{
					pos=j;
					break;
				}
			}
			__int64 mini=10000000000000000;
			for (__int64 j=0;j<N;j++)
			{
				ans+=dist[j];
				tt[j]=ans;
			}
			ans*=2;
			for (__int64 j=0;j<N;j++)
			{
				for (__int64 k=j+1;k<N;k++)
				{
					__int64 tempans;
					if (j<pos)
					{
						tempans=ans;
					}
					else if (j>pos)
					{
						tempans=ans-dist[j];
					}
					else 
					{
						if (j>0)
							tempans=ans-dist[j]+(T-tt[j-1])*0.5;
						else tempans=ans-dist[j]+(T)*0.5;
					}
					if (k<pos)
					{
						tempans=ans;
					}
					else if (k>pos)
					{
						tempans=ans-dist[k];
					}
					else 
					{
						if (k>0)
							tempans=ans-dist[k]+(T-tt[k-1])*0.5;
						else tempans=ans-dist[k]+(T)*0.5;
					}
					mini=tempans<mini?tempans:mini;
				}
			}
			ans=mini;
		}
		cout<<"Case #"<<i<<": "<<ans<<endl;
	}
	return 0;
}