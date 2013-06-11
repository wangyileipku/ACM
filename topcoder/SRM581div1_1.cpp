
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
using namespace std;
class SurveillanceSystem
{
public:
	bool visited[55];
	bool tmpvisit[55];
	int sur[55];
	vector<int> pos[55];
	int len,num,globalcnt,LL;
	void find(int id,int lastfirst, int last)
	{
		if (id == num)
		{
			memset(tmpvisit,0,sizeof(tmpvisit));
			for (int i=0;i<=len-LL;i++)
			{
				if (visited[i])
				{
					for (int j=i;j<i+LL;j++)
					{
						tmpvisit[j]=true;
					}
				}
			}
			for (int i=0;i<len;i++)
			{
				if (tmpvisit[i])
					sur[i]++;
			}
			globalcnt++;
			return ;
		}
		int l = pos[id].size();
		int i;
		if (pos[id][0] == lastfirst)
			i = last+1;
		else i = 0;
		for (;i<l;i++)
		{
			if (!visited[pos[id][i]])
			{
				visited[pos[id][i]]=true;
				find(id+1,pos[id][0],i);
				visited[pos[id][i]]=false;
			}
		}
	}
	string getContainerInfo(string containers, vector <int> reports, int L)
	{
		memset(visited,0,sizeof(visited));
		memset(sur,0,sizeof(sur));
		sort(reports.begin(),reports.end());
		len = containers.length();
		num = reports.size();
		globalcnt = 0;
		LL = L;
		for (int i=0;i<num;i++)
		{
			pos[i].clear();
		}
		int i=0;
		int cnt = 0;
		for (;i<L;i++)
		{
			if (containers[i] == 'X')
				cnt++;
		}
		for (;i<=len;i++)
		{
			for (int j=0;j<num;j++)
			{
				if (cnt==reports[j])
					pos[j].push_back(i-L);
				if (cnt < reports[j])
					break;
			}
			if (i==len)
				break;
			if (containers[i-L]=='X')
				cnt--;
			if (containers[i]=='X')
				cnt++;
		}
		find(0,-1,0);
		string ans = containers;
		for (int i=0;i<len;i++)
		{
			if (sur[i]==globalcnt)
				ans[i]='+';
			else if (sur[i]==0)
				ans[i]='-';
			else ans[i]='?';
		}
		return ans;		
	}
};