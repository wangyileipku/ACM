#include <iostream>
#include <stdio.h>
#include <list>
#include <queue>
using namespace std;
class Person
{
public:
	int num;
	double r;
	double x;
	double y;
};
Person p[1005];

int cmp1(const void *e1,const void *e2)
{
	Person *l1=(Person *)e1;
	Person *l2=(Person *)e2;
	if (l1->r>l2->r)
		return -1;
	else return 1;
}

int cmp2(const void *e1,const void *e2)
{
	Person *l1=(Person *)e1;
	Person *l2=(Person *)e2;
	if (l1->num<l2->num)
		return -1;
	else return 1;
}

double dist(Person a,Person b)
{
	double x=a.x-b.x;
	double y=a.y-b.y;
	return sqrt(x*x+y*y);
}
bool good(double x,double y,double r,int j)
{
	Person tmp;
	tmp.x=x;
	tmp.y=y;
	tmp.r=r;
	for (int i=0;i<j;i++)
	{
		if (dist(p[i],tmp)<p[i].r+tmp.r)
			return false;
	}
	return true;
}
int main()
{
	int t;
	int n,w,l;
	cin>>t;
	bool reverse=false;
	for (int i=1;i<=t;i++)
	{	reverse=false;
		memset(p,0,sizeof(p));
		cin>>n>>w>>l;
		if (w<l)
		{
			int tmp=l;
			l=w;
			w=tmp;
			reverse=true;			
		}
		for (int j=0;j<n;j++)
		{
			p[j].num=j;
			cin>>p[j].r;
		}
		qsort(p,n,sizeof(Person),cmp1);
		p[0].x=0;
		p[0].y=0;
		double cury=0;
		double curx=0;
		double curr=p[0].r;
		int start=0;
		for (int j=1;j<n;j++)
		{
			if (curx+curr+p[j].r+1<=w && good(curx+curr+p[j].r+1,cury,p[j].r,j))
			{
				p[j].x=curx+curr+p[j].r+1;
				p[j].y=cury;
				curx=p[j].x;
				curr=p[j].r;
				//cout<<p[j].num<<' '<<0<<endl;
			}
			else if (j-start<2 &&cury+curr+p[j].r+1<=l)
			{
				p[j].x=curx;
				p[j].y=cury+curr+p[j].r+1;
				cury=p[j].y;
				curr=p[j].r;
				start=j;
				//cout<<p[j].num<<' '<<1<<endl;
			}
			else
			{
				double r1=p[start].r;
				double r2=p[start+1].r;
				double r3=p[j].r;
				double tmpx=((r2+r3)*(r2+r3)-(r1+r3)*(r1+r3)-(r1+r2)*(r1+r2))/(-2.0*(r1+r2));
				double tmpy=sqrt((r1+r3)*(r1+r3)-tmpx*tmpx);
				if (p[start].x+tmpx<=w && p[start].y+tmpy+1<=l)
				{
					p[j].x=p[start].x+tmpx;
					p[j].y=p[start].y+tmpy+1;
					curx=p[j].x;
					cury=p[j].y;
					curr=p[j].r;
					start=j;
					//cout<<p[j].num<<' '<<2<<endl;
				}
				else
				{
					cout<<p[start].x+tmpx<<' '<< p[start].y+tmpy<<endl;
					cout<<"Cao!"<<p[j].r<<endl;
				}
			}
		}
		qsort(p,n,sizeof(Person),cmp2);
		printf("Case #%d:",i);
		for (int j=0;j<n;j++)
		{
			if (reverse)
				printf(" %.1f %.1f",p[j].y,p[j].x);
			else printf(" %.1f %.1f",p[j].x,p[j].y);
			//printf(" %.1f",p[j].r);
		}
		printf("\n");
		for (int j=0;j<n;j++)
		{
			if (p[j].x>w ||p[j].y>l || p[j].x<0||p[j].y<0)
				cout<<"Caonima!"<<endl;
			for (int k=j+1;k<n;k++)
				if (dist(p[j],p[k])<=p[j].r+p[k].r)
				{
					cout<<j<<' '<<k<<endl;
					cout<<dist(p[j],p[k])<<' '<<p[j].r+p[k].r<<endl;
				}

		}

	}
	return 0;
}

