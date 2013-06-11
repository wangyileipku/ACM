#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <cmath>
#include <memory.h>
#include <algorithm>
using namespace std;
int n,k;
struct node
{
	int x,y;
}c[110][30];
bool tu[110][110];
bool col[110][110];
struct rec
{
	int id;
	int du;
	bool used;
}r[110];
int det(node a,node b1,node b2)
{
	int x1=a.x-b1.x;
	int x2=a.x-b2.x;
	int y1=a.y-b1.y;
	int y2=a.y-b2.y;
	return (x1*y2-x2*y1);
}
bool intersect(node a1,node a2,node b1,node b2)
{
	if ((det(a1,b1,b2)*det(a2,b1,b2)<=0)&&(det(b1,a1,a2)*det(b2,a1,a2)<=0))
		return 1;
	return 0;
}
bool jiao(int j,int l)
{
	for (int a=0;a<k-1;a++)
		for (int b=0;b<k-1;b++)
		{
			if (intersect(c[j][a],c[j][a+1],c[l][b],c[l][b+1]))
				return 1;
		}
	return 0;
}
int cmp(const void *e1,const void *e2)
{
	rec *l1=(rec *)e1;
	rec *l2=(rec *)e2;
	return l2->du-l1->du;
}
int main()
{
	int t;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>n>>k;
		memset(c,0,sizeof(c));
		memset(tu,0,sizeof(tu));
		memset(r,0,sizeof(r));
		memset(col,0,sizeof(col));
		for (int j=0;j<n;j++)
		{
			r[j].id=j;
			for (int l=0;l<k;l++)
			{
				c[j][l].x=l;
				cin>>c[j][l].y;
			}
		}
		for (int j=0;j<n;j++)
			for (int l=j+1;l<n;l++)
			{
				if (jiao(j,l))
				{
					tu[j][l]=tu[l][j]=1;
					r[j].du++;
					r[l].du++;
				}
			}
		int ind=-1;
		int cnt=0;
		while(cnt<n)
		{
			qsort(r,n,sizeof(rec),cmp);
			int j,l;
			for (j=0;j<n;j++)
				if (!r[j].used)
					break;
			for (l=0;l<n;l++)
				if (col[r[j].id][l]==0)
				{
					if (l>ind)
						ind=l;
					r[j].used=1;
					r[j].du=0;
					cnt++;
					break;
				}
			for (int u=0;u<n;u++)
			{
				if (tu[r[u].id][r[j].id])
				{
					r[u].du--;
					col[r[u].id][l]=1;
				}
			}
		}
		cout<<"Case #"<<i<<": "<<ind+1<<endl;
		
	}
}