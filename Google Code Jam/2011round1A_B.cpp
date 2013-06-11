#include <iostream>
#include <list>
using namespace std;
int main()
{
	int t,n,m;
	char d[10005][12];
	char l[105][26];
	char cur[12];
	bool needera[10005];
	list<int> can,orican;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>n>>m;
		orican.clear();
		for (int j=0;j<n;j++)
		{
			cin>>d[j];
			orican.push_back(j);
		}
		for (int j=0;j<m;j++)
			cin>>l[j];


		cout<<"Case #"<<i<<":";
		for (int k=0;k<m;k++)
		{
			int maxi=-1;
			int res;
			can.clear();
			for (int j=0;j<n;j++)
			{
				int cnt=0;
				memset(cur,0,sizeof(cur));
				can = orican;
				for (int p=0;p<26;p++)
				{
					memset(needera,0,sizeof(needera));
					bool guess=0;
					list<int>::iterator listi=can.begin(),backlisti=listi;
					for (;listi!=can.end();)
					{
						backlisti=listi;
						backlisti++;
						bool flag=0,era=0;
						int now=(*listi);
						if (strlen(d[now])!=strlen(d[j]))
						{
							era=1;
						}
						else
						{
							for (int o=0;o<10;o++)
							{
								if (d[now][o]!=cur[o] && cur[o]!=0)
								{
									era=1;
									break;
								}
								if (d[now][o]==l[k][p]){
									flag=1;
									needera[now]=1;
								} 
							}
						}
						if (era==1)
						{
							can.erase(listi);
							listi=backlisti;
						}
						else if (flag==1)
						{
							listi++;
							guess=1;
						}
						else 
							listi++;
					}
					bool correct=0;
					for (int o=0;o<10;o++)
					{
						if (d[j][o]==l[k][p])
						{
							cur[o]=d[j][o];
							correct=1;
						}
					}
					if (guess && !correct)
					{
						cnt++;
						list<int>::iterator listi=can.begin(),backlisti=listi;
						for (;listi!=can.end();)
						{
							backlisti=listi;
							backlisti++;
							int now=(*listi);
							if (needera[now])
							{
								can.erase(listi);
								listi=backlisti;
							}
							else
								listi++;
						}
					}
					if (can.size()==1)
					{
						break;
					}
				}
				if (cnt>maxi)
				{
					maxi=cnt;
					res=j;
				}
			}
			cout<<" "<<d[res];
		}
		cout<<endl;

	}
	return 0;
}