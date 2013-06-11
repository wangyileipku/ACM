#include <iostream>
#include <set>
using namespace std;
int n,k;
int a[100005];
int b[100005];
int ans[100005];
int anst[100005];
struct node
{
	bool mytype;
	bool valid;
	int weapon;
	int t;
	int myleft;
	int myright;
	int power;
};
bool operator <(const node e1,const node e2)
{
	return e1.power<e2.power;
}
int main()
{
	cin>>n>>k;
	for (int i=0;i<n;i++)
		cin>>a[i]>>b[i];
	int cnt = 0;
	multiset<node> myset;
	for (int i=0;i<n;i++)
	{
		node temp;
		temp.mytype = 0;
		temp.valid = 1;
		temp.weapon = i;
		temp.t = 1;
		temp.power = a[i] + b[i] * temp.t;
		myset.insert(temp);
	}
	int result = 0;
	int last = -1;
	while(cnt != k)
	{
		multiset<node>::iterator it = myset.begin();
		node temp = *it;
		myset.erase(it);
		bool newnode = false;
		if (temp.power == last || temp.valid == 0)
		{
			;
		}
		else
		{
			newnode = true;
			result = temp.power;
			last = result;
			ans[cnt] = result;
			if (temp.mytype == 0)
				anst[cnt] = temp.t;
			else anst[cnt] = -1;
		}
		if (temp.mytype == 0)
		{
			node newtemp;
			newtemp.mytype = 0;
			newtemp.valid = 1;
			newtemp.weapon = temp.weapon;
			newtemp.t = temp.t + 1;
			newtemp.power = a[newtemp.weapon] + b[newtemp.weapon] * newtemp.t;
			myset.insert(newtemp);
		}
		else
		{
			node newtemp;
			newtemp.mytype = 1;
			newtemp.myleft = temp.myleft;
			newtemp.myright = temp.myright + 1;
			if (anst[newtemp.myleft] == anst[newtemp.myright] && anst[newtemp.myleft] != -1)
				newtemp.valid = 0;
			else
				newtemp.valid = 1;
			newtemp.power = ans[newtemp.myleft] + ans[newtemp.myright];
			myset.insert(newtemp);
		}
		if (newnode)
		{
			node newtemp;
			newtemp.mytype = 1;
			newtemp.myleft = cnt;
			newtemp.myright = cnt;
			newtemp.valid = 0;
			newtemp.power = ans[newtemp.myleft] + ans[newtemp.myright];
			myset.insert(newtemp);
			cnt ++;
		}

	}
	cout<<result<<endl;
	return 0;

}