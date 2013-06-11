#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <cmath>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
long long MOD = 1000002013;
class Interval
{
public:
	long long id;
	long long cnt;
	int shang;
	Interval(long long id_ = 0,long long cnt_=0,int s_=0)
	{
		id=id_;
		cnt = cnt_;
		shang = s_;
	}
};
bool operator < (const Interval &a,const Interval &b)
{
	if (a.id!=b.id)
		return a.id<b.id;
	else return a.shang>b.shang;
}
int main()
{
	long long T,N,M,o,e,p;
	Interval eve[2005];
	cin>>T;
	for (int cs=1;cs<=T;cs++)
	{
		cin>>N>>M;
		long long cnt = 0;
		long long ori=0,aft=0,cha;
		for (long long i=0;i<M;i++)
		{
			cin>>o>>e>>p;
			eve[cnt++]=Interval(o,p,1);
			eve[cnt++]=Interval(e,p,0);
			cha = e-o;
			ori += (p*(((N+N-(cha-1))*cha/2)%MOD))%MOD;
			ori %= MOD;
		}
		sort(eve,eve+cnt);
		stack<Interval> sta;

		for (long long i=0;i<cnt;i++)
		{
			if (eve[i].shang)
			{
				sta.push(eve[i]);
				continue;
			}
			Interval cur= sta.top();
			sta.pop();
			while(cur.cnt<eve[i].cnt)
			{
				cha = eve[i].id-cur.id;
				aft += (cur.cnt*(((N+N-cha+1)*cha/2)%MOD))%MOD;
				aft %= MOD;
				eve[i].cnt -= cur.cnt;
				cur = sta.top();
				sta.pop();
			}
			if (cur.cnt>eve[i].cnt)
			{
				cha = eve[i].id-cur.id;
				aft += (eve[i].cnt*(((N+N-cha+1)*cha/2)%MOD))%MOD;
				aft %= MOD;
				cur.cnt -= eve[i].cnt;
				sta.push(cur);
			}
			else
			{
				cha = eve[i].id-cur.id;
				aft += (eve[i].cnt*(((N+N-cha+1)*cha/2)%MOD))%MOD;
				aft %= MOD;
			}
		}
		//cout<<ori<<' '<<aft<<endl;
		cout<<"Case #"<<cs<<": "<<(ori+MOD-aft)%MOD<<endl;
	}

	return 0;
}