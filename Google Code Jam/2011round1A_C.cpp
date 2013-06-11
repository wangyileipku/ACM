#include <iostream>
#include <list>
using namespace std;
int p[100],tu[100],c[100];
int play(list<int> hand,list<int> deck,int point,int turn,int cnt)
{
	if (turn==0)
		return point;
	list<int>::iterator draw=deck.begin(),back=draw;
	for (;draw!=deck.end()&&cnt>0;cnt--)
	{
		back++;
		hand.push_back(*draw);
		deck.erase(draw);
		draw=back;
	}
	turn--;
	int maxi=point;
	list<int> temp=hand;
	list<int>::iterator j=hand.begin();
	for (;j!=hand.end();j++)
	{
		temp.clear();
		int now=*j;
		list<int>::iterator k=hand.begin();
		for (;k!=hand.end();k++)
			if (*k==now)
			{
				continue;
			}
			else
				temp.push_back(*k);
		int t=play(temp,deck,point+p[now],turn+tu[now],c[now]);
		if (t>maxi)
		{
			maxi=t;
		}
	}
	return maxi;
}
int main()
{
	int t,n,m;
	list<int> hand;
	list<int> deck;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>n;
		int j;
		for (j=0;j<n;j++)
		{
			cin>>c[j]>>p[j]>>tu[j];
			hand.push_back(j);
		}
		cin>>m;
		for (;j<n+m;j++)
		{
			cin>>c[j]>>p[j]>>tu[j];
			deck.push_back(j);
		}

		cout<<"Case #"<<i<<": "<<play(hand,deck,0,1,0)<<endl;
	}
	return 0;
}