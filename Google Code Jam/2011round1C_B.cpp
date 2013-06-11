#include <iostream>
#include <list>
using namespace std;
__int64 fre[10001];
__int64 gcd(__int64 a,__int64 b)
{
	if (b==0)
		return a;
	else return gcd(b,a%b);
}
int main()
{
	list<__int64> lst;
	int t,n,l,h;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		lst.clear();
		cin>>n>>l>>h;
		__int64 maxd=-1,minm=-1;
		bool maxi=0,mini=0;
		for (int j=0;j<n;j++)
		{
			cin>>fre[j];
			if (fre[j]<l)
			{
				if (mini==0)
				{
					mini=1;
					minm=fre[j];
				}
				else minm=fre[j]*minm/gcd(fre[j],minm);
			}
			else if (fre[j]>h)
			{
				if (maxi==0)
				{
					maxi=1;
					maxd=fre[j];
				}
				else maxd=gcd(fre[j],maxd);
			}
			else lst.push_back(fre[j]);
		}
		bool flag=0;
		__int64 ans;
		int inc=1;
		for (__int64 k=l;k<=h;k+=inc)
		{
			if (minm!=-1&&k%minm!=0)
				continue;
			if (minm!=-1)
				inc=minm;
			if (maxd!=-1&&maxd%k!=0)
				continue;
			list<__int64>::iterator j=lst.begin();
			bool can=1;
			for (;j!=lst.end();j++)
			{
				__int64 now=*j;
				if (now%k==0||k%now==0)
					continue;
				else
				{
					can=0;
					break;
				}
			}
			if (can==1)
			{
				flag=1;
				ans=k;
				break;
			}
		}
		cout<<"Case #"<<i<<": ";
		if (flag==0)
			cout<<"NO"<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}