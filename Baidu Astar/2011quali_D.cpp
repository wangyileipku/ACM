

#include <iostream>
#include <stdio.h>
#include <list>
#include <queue>
#include <map>
#include <cmath>
using namespace std;
long double EPS=1e-8;
long double pi=asin(1.0)*2.0;
int main()
{
	long double C;
	long double x1,y1,x2,y2,x3,y3;
	long double t1,t2,t3;
	int cnt=1;
	while(cin>>C)
	{
		if (C==0) break;
		C/=1000.0;
		cin>>x1>>y1>>x2>>y2>>x3>>y3;
		cin>>t1>>t2>>t3;
		bool flag=false;
		long double d21=C*(t2-t1);
		long double d31=C*(t3-t1);
		long double x21=x2-x1;
		long double x31=x3-x1;
		long double y21=y2-y1;
		long double y31=y3-y1;
		long double a=(d31*d31-x31*x31-y31*y31)*x21-(d21*d21-x21*x21-y21*y21)*x31;
		long double b=(d31*d31-x31*x31-y31*y31)*y21-(d21*d21-x21*x21-y21*y21)*y31;
		long double c=-(d31*d31-x31*x31-y31*y31)*d21+(d21*d21-x21*x21-y21*y21)*d31;
		long double tmp = c/(sqrt(a*a+b*b));
		if (fabs(sqrt(a*a+b*b))<EPS)
			flag=true;
		if (tmp>1.0) tmp=1.0;
		if (tmp<-1.0) tmp=-1.0;
		long double theta=asin(tmp)-atan2(a,b);
		long double r=(x21*x21+y21*y21-d21*d21)/(2*(x21*cos(theta)+y21*sin(theta)+d21));
		if (fabs(x21*cos(theta)+y21*sin(theta)+d21)<EPS)
			flag=true;
		//cout<<x21<<' '<<y21<<' '<<d21<<endl;
		//cout<<x31<<' '<<y31<<' '<<d31<<endl;
		//cout<<a<<' '<<b<<' '<<c<<endl;
		//cout<<asin(tmp)<<' '<<(x21*cos(theta)+y21*sin(theta)+d21)<<endl;
		//cout<<atan2(a,b)<<endl;
		//cout<<theta<<' '<<r<<endl;
		if (flag)
		{
			flag=false;
			d21=C*(t3-t1);
			d31=C*(t2-t1);
			x21=x3-x1;
			x31=x2-x1;
			y21=y3-y1;
			y31=y2-y1;
			a=(d31*d31-x31*x31-y31*y31)*x21-(d21*d21-x21*x21-y21*y21)*x31;
			b=(d31*d31-x31*x31-y31*y31)*y21-(d21*d21-x21*x21-y21*y21)*y31;
			c=-(d31*d31-x31*x31-y31*y31)*d21+(d21*d21-x21*x21-y21*y21)*d31;
			if (fabs(sqrt(a*a+b*b))<EPS)
				flag=true;
			tmp = c/(sqrt(a*a+b*b));
			if (tmp>1.0) tmp=1.0;
			if (tmp<-1.0) tmp=-1.0;
			theta=asin(tmp)-atan2(a,b);
			r=(x21*x21+y21*y21-d21*d21)/(2*(x21*cos(theta)+y21*sin(theta)+d21));
			if (fabs(x21*cos(theta)+y21*sin(theta)+d21)<EPS)
				flag=true;
			//cout<<x21<<' '<<y21<<' '<<d21<<endl;
			//cout<<x31<<' '<<y31<<' '<<d31<<endl;
			//cout<<a<<' '<<b<<' '<<c<<endl;
			//cout<<asin(tmp)<<' '<<(x21*cos(theta)+y21*sin(theta)+d21)<<endl;
			//cout<<atan2(a,b)<<endl;
			//cout<<theta<<' '<<r<<endl;
			if (flag)
			{
				flag=false;
				{
					long double tx=x2;
					long double ty=y2;
					long double tt=t2;
					x2=x1;
					y2=y1;
					t2=t1;
					x1=tx;
					y1=ty;
					t1=tt;
				}
				d21=C*(t3-t1);
				d31=C*(t2-t1);
				x21=x3-x1;
				x31=x2-x1;
				y21=y3-y1;
				y31=y2-y1;
				a=(d31*d31-x31*x31-y31*y31)*x21-(d21*d21-x21*x21-y21*y21)*x31;
				b=(d31*d31-x31*x31-y31*y31)*y21-(d21*d21-x21*x21-y21*y21)*y31;
				c=-(d31*d31-x31*x31-y31*y31)*d21+(d21*d21-x21*x21-y21*y21)*d31;
				if (fabs(sqrt(a*a+b*b))<EPS)
					flag=true;
				tmp = c/(sqrt(a*a+b*b));
				if (tmp>1.0) tmp=1.0;
				if (tmp<-1.0) tmp=-1.0;
				theta=asin(tmp)-atan2(a,b);
				r=(x21*x21+y21*y21-d21*d21)/(2*(x21*cos(theta)+y21*sin(theta)+d21));
				if (fabs(x21*cos(theta)+y21*sin(theta)+d21)<EPS)
					flag=true;
				if (flag)
				{
					flag=false;
					d21=C*(t2-t1);
					d31=C*(t3-t1);
					x21=x2-x1;
					x31=x3-x1;
					y21=y2-y1;
					y31=y3-y1;
					a=(d31*d31-x31*x31-y31*y31)*x21-(d21*d21-x21*x21-y21*y21)*x31;
					b=(d31*d31-x31*x31-y31*y31)*y21-(d21*d21-x21*x21-y21*y21)*y31;
					c=-(d31*d31-x31*x31-y31*y31)*d21+(d21*d21-x21*x21-y21*y21)*d31;
					if (fabs(sqrt(a*a+b*b))<EPS)
						flag=true;
					tmp = c/(sqrt(a*a+b*b));
					if (tmp>1.0) tmp=1.0;
					if (tmp<-1.0) tmp=-1.0;
					theta=asin(tmp)-atan2(a,b);
					r=(x21*x21+y21*y21-d21*d21)/(2*(x21*cos(theta)+y21*sin(theta)+d21));
					if (fabs(x21*cos(theta)+y21*sin(theta)+d21)<EPS)
						flag=true;
					if (flag)
					{
						flag=false;
						{
							long double tx=x3;
							long double ty=y3;
							long double tt=t3;
							x3=x1;
							y3=y1;
							t3=t1;
							x1=tx;
							y1=ty;
							t1=tt;
						}
						d21=C*(t3-t1);
						d31=C*(t2-t1);
						x21=x3-x1;
						x31=x2-x1;
						y21=y3-y1;
						y31=y2-y1;
						a=(d31*d31-x31*x31-y31*y31)*x21-(d21*d21-x21*x21-y21*y21)*x31;
						b=(d31*d31-x31*x31-y31*y31)*y21-(d21*d21-x21*x21-y21*y21)*y31;
						c=-(d31*d31-x31*x31-y31*y31)*d21+(d21*d21-x21*x21-y21*y21)*d31;
						if (fabs(sqrt(a*a+b*b))<EPS)
							flag=true;
						tmp = c/(sqrt(a*a+b*b));
						if (tmp>1.0) tmp=1.0;
						if (tmp<-1.0) tmp=-1.0;
						theta=asin(tmp)-atan2(a,b);
						r=(x21*x21+y21*y21-d21*d21)/(2*(x21*cos(theta)+y21*sin(theta)+d21));
						if (fabs(x21*cos(theta)+y21*sin(theta)+d21)<EPS)
							flag=true;
						if (flag)
						{
							flag=false;
							d21=C*(t2-t1);
							d31=C*(t3-t1);
							x21=x2-x1;
							x31=x3-x1;
							y21=y2-y1;
							y31=y3-y1;
							a=(d31*d31-x31*x31-y31*y31)*x21-(d21*d21-x21*x21-y21*y21)*x31;
							b=(d31*d31-x31*x31-y31*y31)*y21-(d21*d21-x21*x21-y21*y21)*y31;
							c=-(d31*d31-x31*x31-y31*y31)*d21+(d21*d21-x21*x21-y21*y21)*d31;
							if (fabs(sqrt(a*a+b*b))<EPS)
								flag=true;
							tmp = c/(sqrt(a*a+b*b));
							if (tmp>1.0) tmp=1.0;
							if (tmp<-1.0) tmp=-1.0;
							theta=asin(tmp)-atan2(a,b);
							r=(x21*x21+y21*y21-d21*d21)/(2*(x21*cos(theta)+y21*sin(theta)+d21));
							if (fabs(x21*cos(theta)+y21*sin(theta)+d21)<EPS)
								flag=true;
						}
					}
				}
			}
		}
		long double x=r*cos(theta)+x1;
		long double y=r*sin(theta)+y1;
		if (fabs(x)<EPS)
			x=0.0;
		if (fabs(y)<EPS)
			y=0.0;
		long double T1=sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1))/C;
		long double T2=sqrt((x-x2)*(x-x2)+(y-y2)*(y-y2))/C;
		long double T3=sqrt((x-x3)*(x-x3)+(y-y3)*(y-y3))/C;
		//cout<<T1<<' '<<T2<<' '<<T3<<endl;
		if (T1<t1-EPS || T2<t2-EPS||T3<t3-EPS)
		{
			//cout<<"here"<<endl;
			flag=false;
			d21=C*(t2-t1);
			d31=C*(t3-t1);
			x21=x2-x1;
			x31=x3-x1;
			y21=y2-y1;
			y31=y3-y1;
			a=(d31*d31-x31*x31-y31*y31)*x21-(d21*d21-x21*x21-y21*y21)*x31;
			b=(d31*d31-x31*x31-y31*y31)*y21-(d21*d21-x21*x21-y21*y21)*y31;
			c=-(d31*d31-x31*x31-y31*y31)*d21+(d21*d21-x21*x21-y21*y21)*d31;
			tmp = c/(sqrt(a*a+b*b));
			if (fabs(sqrt(a*a+b*b))<EPS)
				flag=true;
			if (tmp>1.0) tmp=1.0;
			if (tmp<-1.0) tmp=-1.0;
			theta=pi-asin(tmp)-atan2(a,b);
			r=(x21*x21+y21*y21-d21*d21)/(2*(x21*cos(theta)+y21*sin(theta)+d21));
			if (fabs(x21*cos(theta)+y21*sin(theta)+d21)<EPS)
				flag=true;
			//cout<<x21<<' '<<y21<<' '<<d21<<endl;
			//cout<<x31<<' '<<y31<<' '<<d31<<endl;
			//cout<<a<<' '<<b<<' '<<c<<endl;
			//cout<<asin(tmp)<<' '<<(x21*cos(theta)+y21*sin(theta)+d21)<<endl;
			//cout<<atan2(a,b)<<endl;
			//cout<<theta<<' '<<r<<endl;
			if (flag)
			{
				flag=false;
				d21=C*(t3-t1);
				d31=C*(t2-t1);
				x21=x3-x1;
				x31=x2-x1;
				y21=y3-y1;
				y31=y2-y1;
				a=(d31*d31-x31*x31-y31*y31)*x21-(d21*d21-x21*x21-y21*y21)*x31;
				b=(d31*d31-x31*x31-y31*y31)*y21-(d21*d21-x21*x21-y21*y21)*y31;
				c=-(d31*d31-x31*x31-y31*y31)*d21+(d21*d21-x21*x21-y21*y21)*d31;
				if (fabs(sqrt(a*a+b*b))<EPS)
					flag=true;
				tmp = c/(sqrt(a*a+b*b));
				if (tmp>1.0) tmp=1.0;
				if (tmp<-1.0) tmp=-1.0;
				theta=pi-asin(tmp)-atan2(a,b);
				r=(x21*x21+y21*y21-d21*d21)/(2*(x21*cos(theta)+y21*sin(theta)+d21));
				if (fabs(x21*cos(theta)+y21*sin(theta)+d21)<EPS)
					flag=true;
				//cout<<x21<<' '<<y21<<' '<<d21<<endl;
				//cout<<x31<<' '<<y31<<' '<<d31<<endl;
				//cout<<a<<' '<<b<<' '<<c<<endl;
				//cout<<asin(tmp)<<' '<<(x21*cos(theta)+y21*sin(theta)+d21)<<endl;
				//cout<<atan2(a,b)<<endl;
				//cout<<theta<<' '<<r<<endl;
				if (flag)
				{
					flag=false;
					{
						long double tx=x2;
						long double ty=y2;
						long double tt=t2;
						x2=x1;
						y2=y1;
						t2=t1;
						x1=tx;
						y1=ty;
						t1=tt;
					}
					d21=C*(t3-t1);
					d31=C*(t2-t1);
					x21=x3-x1;
					x31=x2-x1;
					y21=y3-y1;
					y31=y2-y1;
					a=(d31*d31-x31*x31-y31*y31)*x21-(d21*d21-x21*x21-y21*y21)*x31;
					b=(d31*d31-x31*x31-y31*y31)*y21-(d21*d21-x21*x21-y21*y21)*y31;
					c=-(d31*d31-x31*x31-y31*y31)*d21+(d21*d21-x21*x21-y21*y21)*d31;
					if (fabs(sqrt(a*a+b*b))<EPS)
						flag=true;
					tmp = c/(sqrt(a*a+b*b));
					if (tmp>1.0) tmp=1.0;
					if (tmp<-1.0) tmp=-1.0;
					theta=pi-asin(tmp)-atan2(a,b);
					r=(x21*x21+y21*y21-d21*d21)/(2*(x21*cos(theta)+y21*sin(theta)+d21));
					if (fabs(x21*cos(theta)+y21*sin(theta)+d21)<EPS)
						flag=true;
					if (flag)
					{
						flag=false;
						d21=C*(t2-t1);
						d31=C*(t3-t1);
						x21=x2-x1;
						x31=x3-x1;
						y21=y2-y1;
						y31=y3-y1;
						a=(d31*d31-x31*x31-y31*y31)*x21-(d21*d21-x21*x21-y21*y21)*x31;
						b=(d31*d31-x31*x31-y31*y31)*y21-(d21*d21-x21*x21-y21*y21)*y31;
						c=-(d31*d31-x31*x31-y31*y31)*d21+(d21*d21-x21*x21-y21*y21)*d31;
						if (fabs(sqrt(a*a+b*b))<EPS)
							flag=true;
						tmp = c/(sqrt(a*a+b*b));
						if (tmp>1.0) tmp=1.0;
						if (tmp<-1.0) tmp=-1.0;
						theta=pi-asin(tmp)-atan2(a,b);
						r=(x21*x21+y21*y21-d21*d21)/(2*(x21*cos(theta)+y21*sin(theta)+d21));
						if (fabs(x21*cos(theta)+y21*sin(theta)+d21)<EPS)
							flag=true;
						if (flag)
						{
							flag=false;
							{
								long double tx=x3;
								long double ty=y3;
								long double tt=t3;
								x3=x1;
								y3=y1;
								t3=t1;
								x1=tx;
								y1=ty;
								t1=tt;
							}
							d21=C*(t3-t1);
							d31=C*(t2-t1);
							x21=x3-x1;
							x31=x2-x1;
							y21=y3-y1;
							y31=y2-y1;
							a=(d31*d31-x31*x31-y31*y31)*x21-(d21*d21-x21*x21-y21*y21)*x31;
							b=(d31*d31-x31*x31-y31*y31)*y21-(d21*d21-x21*x21-y21*y21)*y31;
							c=-(d31*d31-x31*x31-y31*y31)*d21+(d21*d21-x21*x21-y21*y21)*d31;
							if (fabs(sqrt(a*a+b*b))<EPS)
								flag=true;
							tmp = c/(sqrt(a*a+b*b));
							if (tmp>1.0) tmp=1.0;
							if (tmp<-1.0) tmp=-1.0;
							theta=pi-asin(tmp)-atan2(a,b);
							r=(x21*x21+y21*y21-d21*d21)/(2*(x21*cos(theta)+y21*sin(theta)+d21));
							if (fabs(x21*cos(theta)+y21*sin(theta)+d21)<EPS)
								flag=true;
							if (flag)
							{
								flag=false;
								d21=C*(t2-t1);
								d31=C*(t3-t1);
								x21=x2-x1;
								x31=x3-x1;
								y21=y2-y1;
								y31=y3-y1;
								a=(d31*d31-x31*x31-y31*y31)*x21-(d21*d21-x21*x21-y21*y21)*x31;
								b=(d31*d31-x31*x31-y31*y31)*y21-(d21*d21-x21*x21-y21*y21)*y31;
								c=-(d31*d31-x31*x31-y31*y31)*d21+(d21*d21-x21*x21-y21*y21)*d31;
								if (fabs(sqrt(a*a+b*b))<EPS)
									flag=true;
								tmp = c/(sqrt(a*a+b*b));
								if (tmp>1.0) tmp=1.0;
								if (tmp<-1.0) tmp=-1.0;
								theta=pi-asin(tmp)-atan2(a,b);
								r=(x21*x21+y21*y21-d21*d21)/(2*(x21*cos(theta)+y21*sin(theta)+d21));
								if (fabs(x21*cos(theta)+y21*sin(theta)+d21)<EPS)
									flag=true;
							}
						}
					}
				}
			}
			x=r*cos(theta)+x1;
			y=r*sin(theta)+y1;
			if (fabs(x)<EPS)
				x=0.0;
			if (fabs(y)<EPS)
				y=0.0;
		}

		 T1=sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1))/C;
		 T2=sqrt((x-x2)*(x-x2)+(y-y2)*(y-y2))/C;
		 T3=sqrt((x-x3)*(x-x3)+(y-y3)*(y-y3))/C;
		//cout<<T1<<' '<<T2<<' '<<T3<<endl;
		if (T1<t1-EPS || T2<t2-EPS||T3<t3-EPS)
			while(1);
		printf("Case %d:\n",cnt++);
		if (fabs(x)<EPS)
			printf("0.000000 ");
		else printf("%.6lf ",x);
		if (fabs(y)<EPS)
			printf("0.000000\n");
		else printf("%.6lf\n",y);
	}
}