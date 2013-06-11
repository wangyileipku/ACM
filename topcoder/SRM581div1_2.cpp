
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
using namespace std;
class Node
{
public:
	int id;
	int level;
	Node(int i,int l)
	{
		id = i;
		level = l;
	}
};
class TreeUnion
{
public:
	int N;
	vector<int> T1[301];
	vector<int> T2[301];
	vector<int> path1[301];
	vector<int> path2[301];
	void findpath()
	{
		bool visited[301];
		for (int i=0;i<N;i++)
		{
			memset(visited,0,sizeof(visited));
			queue<Node> que;
			que.push(Node(i,1));
			for (int j=0;j<7;j++)
				path1[i].push_back(0);
			while(!que.empty())
			{
				Node cur = que.front();
				que.pop();
				if (visited[cur.id])
					continue;
				visited[cur.id] = true;
				if (cur.level > 5)
					break;
				if (cur.level>1)
					path1[i][cur.level]++;
				for (int j=0;j<T1[cur.id].size();j++)
				{
					if (!visited[T1[cur.id][j]])
					{
						que.push(Node(T1[cur.id][j],cur.level+1));
					}
				}
			}
		}
		for (int i=0;i<N;i++)
		{
			memset(visited,0,sizeof(visited));
			queue<Node> que;
			que.push(Node(i,1));
			for (int j=0;j<7;j++)
				path2[i].push_back(0);
			while(!que.empty())
			{
				Node cur = que.front();
				que.pop();
				if (visited[cur.id])
					continue;
				if (cur.level > 5)
					break;
				visited[cur.id] = true;
				if (cur.level>1)
					path2[i][cur.level]++;
				for (int j=0;j<T2[cur.id].size();j++)
				{
					if (!visited[T2[cur.id][j]])
					{
						que.push(Node(T2[cur.id][j],cur.level+1));
					}
				}
			}
		}
	}
	double expectedCycles(vector <string> tree1, vector <string> tree2, int K)
	{
		string ver1="",ver2 = "";
		int len1 = tree1.size();
		int len2 = tree2.size();
		for (int i=0;i<len1;i++)
			ver1 += tree1[i];
		for (int i=0;i<len2;i++)
			ver2 += tree2[i];
		for (int i=0;i<301;i++)
		{
			T1[i].clear();
			T2[i].clear();
		}
		stringstream ss1(ver1),ss2(ver2);
		int cnt = 1;
		int tmp;
		while(ss1>>tmp)
		{
			T1[cnt].push_back(tmp);
			T1[tmp].push_back(cnt);
			cnt++;
		}
		N = cnt;
		cnt = 1;
		while(ss2>>tmp)
		{
			T2[cnt].push_back(tmp);
			T2[tmp].push_back(cnt);
			cnt++;
		}
		findpath();
		long long sum = 0;
		for (int i=0;i<N;i++)
		for (int j=0;j<N;j++)
		{
			for (int a = 2;a<K;a++)
			{
				sum += path1[i][a]*path2[j][K-a];
			}
		}
		double ans = sum;
		return ans/2/N/(N-1);
	}
};