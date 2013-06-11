#include <iostream>
#include <list>
using namespace std;
list<int> room[8];
class Range
{
public:
	int left;
	int right;
};
Range range[8];
int main()
{
	int t,n,m;
	int ans;
	int color[10];
	int maxcolor;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		for (int j=0;j<8;j++)
			room[j].clear();
		maxcolor=0;
		cin>>n>>m;
		for (int j=0;j<m;j++)
			cin>>range[j].left;
		for (int j=0;j<m;j++)
			cin>>range[j].right;
		int cnt=0;
		for (int j=1;j<=8;j++)
		{
			int target=j;
			room[cnt].push_back(j);
			while(target!=j||room[cnt].size()==1)
			{
				bool flag=0;
				for (int k=0;k<m;k++)
				{
					if (range[k].left==j||range[k].right==j)
					{
						flag=1;
						target=range[k].left+range[k].right-j;
						room[cnt].push_back(target);
						break;
					}
				}
				if (flag==0)
				{
					target=target+1;
					room[cnt].push_back(target);
				}
			}
			cnt++;
		}
		for (int j=0;j<cnt;j++)
			maxcolor=maxcolor>room[j].size()?maxcolor:room[j].size();
		int ans;
		for (int j=maxcolor;j>=3;j--)
		{
			memset(color,0,sizeof(color));
			for (color[1]=1;color[1]<=j;color[1]++)
			{
				for (color[2]=1;color[2]<=j;color[2]++)
				{
					for (color[3]=1;color[3]<=j;color[3]++)
					{
						for (color[4]=1;color[4]<=j;color[4]++)
						{
							for (color[5]=1;color[5]<=j;color[5]++)
							{
								for (color[6]=1;color[6]<=j;color[6]++)
								{
									for (color[7]=1;color[7]<=j;color[7]++)
									{

										for (color[8]=1;color[8]<=j;color[8]++)
										{
											bool exist[8]={0};
											for (int k=0;k<cnt;k++)
											{
												list<int>::iterator ll=room[k].begin();
												for (;ll!=room[k].end();ll++)
												{
													exist[color[*ll]]=1;
												}
											}
											bool ok=1;
											for (int k=0;k<j;k++)
												if (!exist[k])
													ok=0;
											if (ok==1)
											{
												ans=j;
												goto label;
											}
										}
									}

								}
							}
						}
					}
				}
			}
		}
		label:
		cout<<"Case #"<<i<<": "<<ans<<endl;
		for (int k=0;k<m;k++)
			cout<<color[k]<<' '<<endl;
	}
	return 0;
}