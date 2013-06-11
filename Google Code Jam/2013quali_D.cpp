#include <iostream>
#include <list>
#include <vector>
using namespace std;

vector<int> trea[205];
int numkey[205];
int key[205];
int numtrea[205];
int ans[205];
bool visited[205];
int T,K,N;
bool find(int n)
{
	if (n==N)
		return true;

	for (int i = 0;i<N;i++)
	{
		if (!visited[i] && numkey[key[i]]>0)
		{
			ans[n]=i;
			numkey[key[i]]--;
			for (int j=0;j<numtrea[i];j++)
				numkey[trea[i][j]]++;
			visited[i]=true;
			if (find(n+1))
				return true;
			numkey[key[i]]++;			
			for (int j=0;j<numtrea[i];j++)
				numkey[trea[i][j]]--;
			visited[i]=false;
		}
	}
	return false;
}
int main()
{
	int tmp;
	cin>>T;
	for (int i=1;i<=T;i++)
	{
		cin>>K>>N;
		for (int j=0;j<N;j++)
		{
			trea[j].clear();
			visited[j]=false;
		}

		for (int j=0;j<K;j++)
		{
			cin>>tmp;
			numkey[tmp]++;
		}
		for (int j=0;j<N;j++)
		{
			cin>>key[j]>>numtrea[j];
			for (int k=0;k<numtrea[j];k++)
			{
				cin>>tmp;
				trea[j].push_back(tmp);
			}
		}
		
		cout<<"Case #"<<i<<":";
		if (find(0))
			for (int j=0;j<N;j++)
				cout<<' '<<ans[j]+1;
			for (int j=0;j<N;j++)

		else
			cout<<" IMPOSSIBLE";
		cout<<endl;
		
		system("pause");
	}
	return 0;
}