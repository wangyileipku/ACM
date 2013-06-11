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
		long double tx,ty,tt;
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

		if (fabs(a*a+b*b)<EPS)
			flag=true;
		long double delta=a*a*c*c-(a*a+b*b)*(c*c-b*b);
		if (fabs(delta)<EPS)
			delta=0;
		long double cost=(a*c+sqrt(delta))/(a*a+b*b);

		if (fabs(cost)>1.0+EPS)
		{
			cost = (a*c-sqrt(a*a*c*c-(a*a+b*b)*(c*c-b*b)))/(a*a+b*b);
		}
		if (fabs(cost)>1.0+EPS)
			flag=true;
		delta=b*b*c*c-(a*a+b*b)*(c*c-a*a);
		if (fabs(delta)<EPS)
			delta=0;
		long double sint = (b*c+sqrt(delta))/(a*a+b*b);
		if (fabs(sint)>1.0+EPS)
		{
			sint = (b*c-sqrt(b*b*c*c-(a*a+b*b)*(c*c-a*a)))/(a*a+b*b);
		}
		if (fabs(sint)>1.0+EPS)
			flag=true;
		long double r=(x21*x21+y21*y21-d21*d21)/(2*(x21*cost+y21*sint+d21));
		if (fabs(x21*cost+y21*sint+d21)<EPS)
			flag=true;
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

			if (fabs(a*a+b*b)<EPS)
				flag=true;
			delta=a*a*c*c-(a*a+b*b)*(c*c-b*b);
			if (fabs(delta)<EPS)
				delta=0;
			cost=(a*c+sqrt(delta))/(a*a+b*b);

			if (fabs(cost)>1.0+EPS)
			{
				cost = (a*c-sqrt(a*a*c*c-(a*a+b*b)*(c*c-b*b)))/(a*a+b*b);
			}
			if (fabs(cost)>1.0+EPS)
				flag=true;
			delta=b*b*c*c-(a*a+b*b)*(c*c-a*a);
			if (fabs(delta)<EPS)
				delta=0;
			sint = (b*c+sqrt(delta))/(a*a+b*b);
			if (fabs(sint)>1.0+EPS)
			{
				sint = (b*c-sqrt(b*b*c*c-(a*a+b*b)*(c*c-a*a)))/(a*a+b*b);
			}
			if (fabs(sint)>1.0+EPS)
				flag=true;
			r=(x21*x21+y21*y21-d21*d21)/(2*(x21*cost+y21*sint+d21));
			if (fabs(x21*cost+y21*sint+d21)<EPS)
				flag=true;
			if (flag)
			{
				flag=false;
				{
					tx=x2;
					ty=y2;
					tt=t2;
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

				if (fabs(a*a+b*b)<EPS)
					flag=true;
				delta=a*a*c*c-(a*a+b*b)*(c*c-b*b);
				if (fabs(delta)<EPS)
					delta=0;
				cost=(a*c+sqrt(delta))/(a*a+b*b);

				if (fabs(cost)>1.0+EPS)
				{
					cost = (a*c-sqrt(a*a*c*c-(a*a+b*b)*(c*c-b*b)))/(a*a+b*b);
				}
				if (fabs(cost)>1.0+EPS)
					flag=true;
				delta=b*b*c*c-(a*a+b*b)*(c*c-a*a);
				if (fabs(delta)<EPS)
					delta=0;
				sint = (b*c+sqrt(delta))/(a*a+b*b);
				if (fabs(sint)>1.0+EPS)
				{
					sint = (b*c-sqrt(b*b*c*c-(a*a+b*b)*(c*c-a*a)))/(a*a+b*b);
				}
				if (fabs(sint)>1.0+EPS)
					flag=true;
				r=(x21*x21+y21*y21-d21*d21)/(2*(x21*cost+y21*sint+d21));
				if (fabs(x21*cost+y21*sint+d21)<EPS)
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

					if (fabs(a*a+b*b)<EPS)
						flag=true;
					delta=a*a*c*c-(a*a+b*b)*(c*c-b*b);
					if (fabs(delta)<EPS)
						delta=0;
					cost=(a*c+sqrt(delta))/(a*a+b*b);

					if (fabs(cost)>1.0+EPS)
					{
						cost = (a*c-sqrt(a*a*c*c-(a*a+b*b)*(c*c-b*b)))/(a*a+b*b);
					}
					if (fabs(cost)>1.0+EPS)
						flag=true;
					delta=b*b*c*c-(a*a+b*b)*(c*c-a*a);
					if (fabs(delta)<EPS)
						delta=0;
					sint = (b*c+sqrt(delta))/(a*a+b*b);
					if (fabs(sint)>1.0+EPS)
					{
						sint = (b*c-sqrt(b*b*c*c-(a*a+b*b)*(c*c-a*a)))/(a*a+b*b);
					}
					if (fabs(sint)>1.0+EPS)
						flag=true;
					r=(x21*x21+y21*y21-d21*d21)/(2*(x21*cost+y21*sint+d21));
					if (fabs(x21*cost+y21*sint+d21)<EPS)
						flag=true;
					if (flag)
					{
						flag=false;
						{
							tx=x3;
							ty=y3;
							tt=t3;
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

						if (fabs(a*a+b*b)<EPS)
							flag=true;
						delta=a*a*c*c-(a*a+b*b)*(c*c-b*b);
						if (fabs(delta)<EPS)
							delta=0;
						cost=(a*c+sqrt(delta))/(a*a+b*b);

						if (fabs(cost)>1.0+EPS)
						{
							cost = (a*c-sqrt(a*a*c*c-(a*a+b*b)*(c*c-b*b)))/(a*a+b*b);
						}
						if (fabs(cost)>1.0+EPS)
							flag=true;
						delta=b*b*c*c-(a*a+b*b)*(c*c-a*a);
						if (fabs(delta)<EPS)
							delta=0;
						sint = (b*c+sqrt(delta))/(a*a+b*b);
						if (fabs(sint)>1.0+EPS)
						{
							sint = (b*c-sqrt(b*b*c*c-(a*a+b*b)*(c*c-a*a)))/(a*a+b*b);
						}
						if (fabs(sint)>1.0+EPS)
							flag=true;
						r=(x21*x21+y21*y21-d21*d21)/(2*(x21*cost+y21*sint+d21));
						if (fabs(x21*cost+y21*sint+d21)<EPS)
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

							if (fabs(a*a+b*b)<EPS)
								flag=true;
							delta=a*a*c*c-(a*a+b*b)*(c*c-b*b);
							if (fabs(delta)<EPS)
								delta=0;
							cost=(a*c+sqrt(delta))/(a*a+b*b);

							if (fabs(cost)>1.0+EPS)
							{
								cost = (a*c-sqrt(a*a*c*c-(a*a+b*b)*(c*c-b*b)))/(a*a+b*b);
							}
							if (fabs(cost)>1.0+EPS)
								flag=true;
							delta=b*b*c*c-(a*a+b*b)*(c*c-a*a);
							if (fabs(delta)<EPS)
								delta=0;
							sint = (b*c+sqrt(delta))/(a*a+b*b);
							if (fabs(sint)>1.0+EPS)
							{
								sint = (b*c-sqrt(b*b*c*c-(a*a+b*b)*(c*c-a*a)))/(a*a+b*b);
							}
							if (fabs(sint)>1.0+EPS)
								flag=true;
							r=(x21*x21+y21*y21-d21*d21)/(2*(x21*cost+y21*sint+d21));
							if (fabs(x21*cost+y21*sint+d21)<EPS)
								flag=true;
						}
					}
				}
			}
		}
		long double x=r*cost+x1;
		long double y=r*sint+y1;
		if (fabs(x)<EPS)
			x=0.0;
		if (fabs(y)<EPS)
			y=0.0;
		long double T1=sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1))/C;
		long double T2=sqrt((x-x2)*(x-x2)+(y-y2)*(y-y2))/C;
		long double T3=sqrt((x-x3)*(x-x3)+(y-y3)*(y-y3))/C;
		//cout<<cost<<' '<<sint<<endl;
		//cout<<r<<endl;
		//cout<<T1<<' '<<T2<<' '<<T3<<endl;
		if (T1<t1-EPS || T2<t2-EPS||T3<t3-EPS)
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

			if (fabs(a*a+b*b)<EPS)
				flag=true;
			delta=a*a*c*c-(a*a+b*b)*(c*c-b*b);
			if (fabs(delta)<EPS)
				delta=0;
			cost=(a*c-sqrt(delta))/(a*a+b*b);

			if (fabs(cost)>1.0+EPS)
			{
				cost = (a*c+sqrt(a*a*c*c-(a*a+b*b)*(c*c-b*b)))/(a*a+b*b);
			}
			if (fabs(cost)>1.0+EPS)
				flag=true;
			delta=b*b*c*c-(a*a+b*b)*(c*c-a*a);
			if (fabs(delta)<EPS)
				delta=0;
			sint = (b*c-sqrt(delta))/(a*a+b*b);
			if (fabs(sint)>1.0+EPS)
			{
				sint = (b*c+sqrt(b*b*c*c-(a*a+b*b)*(c*c-a*a)))/(a*a+b*b);
			}
			if (fabs(sint)>1.0+EPS)
				flag=true;
			r=(x21*x21+y21*y21-d21*d21)/(2*(x21*cost+y21*sint+d21));
			if (fabs(x21*cost+y21*sint+d21)<EPS)
				flag=true;
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

				if (fabs(a*a+b*b)<EPS)
					flag=true;
				delta=a*a*c*c-(a*a+b*b)*(c*c-b*b);
				if (fabs(delta)<EPS)
					delta=0;
				cost=(a*c-sqrt(delta))/(a*a+b*b);

				if (fabs(cost)>1.0+EPS)
				{
					cost = (a*c+sqrt(a*a*c*c-(a*a+b*b)*(c*c-b*b)))/(a*a+b*b);
				}
				if (fabs(cost)>1.0+EPS)
					flag=true;
				delta=b*b*c*c-(a*a+b*b)*(c*c-a*a);
				if (fabs(delta)<EPS)
					delta=0;
				sint = (b*c-sqrt(delta))/(a*a+b*b);
				if (fabs(sint)>1.0+EPS)
				{
					sint = (b*c+sqrt(b*b*c*c-(a*a+b*b)*(c*c-a*a)))/(a*a+b*b);
				}
				if (fabs(sint)>1.0+EPS)
					flag=true;
				r=(x21*x21+y21*y21-d21*d21)/(2*(x21*cost+y21*sint+d21));
				if (fabs(x21*cost+y21*sint+d21)<EPS)
					flag=true;
				if (flag)
				{
					flag=false;
					{
						tx=x2;
						ty=y2;
						tt=t2;
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

					if (fabs(a*a+b*b)<EPS)
						flag=true;
					delta=a*a*c*c-(a*a+b*b)*(c*c-b*b);
					if (fabs(delta)<EPS)
						delta=0;
					cost=(a*c-sqrt(delta))/(a*a+b*b);

					if (fabs(cost)>1.0+EPS)
					{
						cost = (a*c+sqrt(a*a*c*c-(a*a+b*b)*(c*c-b*b)))/(a*a+b*b);
					}
					if (fabs(cost)>1.0+EPS)
						flag=true;
					delta=b*b*c*c-(a*a+b*b)*(c*c-a*a);
					if (fabs(delta)<EPS)
						delta=0;
					sint = (b*c-sqrt(delta))/(a*a+b*b);
					if (fabs(sint)>1.0+EPS)
					{
						sint = (b*c+sqrt(b*b*c*c-(a*a+b*b)*(c*c-a*a)))/(a*a+b*b);
					}
					if (fabs(sint)>1.0+EPS)
						flag=true;
					r=(x21*x21+y21*y21-d21*d21)/(2*(x21*cost+y21*sint+d21));
					if (fabs(x21*cost+y21*sint+d21)<EPS)
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

						if (fabs(a*a+b*b)<EPS)
							flag=true;
						delta=a*a*c*c-(a*a+b*b)*(c*c-b*b);
						if (fabs(delta)<EPS)
							delta=0;
						cost=(a*c-sqrt(delta))/(a*a+b*b);

						if (fabs(cost)>1.0+EPS)
						{
							cost = (a*c+sqrt(a*a*c*c-(a*a+b*b)*(c*c-b*b)))/(a*a+b*b);
						}
						if (fabs(cost)>1.0+EPS)
							flag=true;
						delta=b*b*c*c-(a*a+b*b)*(c*c-a*a);
						if (fabs(delta)<EPS)
							delta=0;
						sint = (b*c-sqrt(delta))/(a*a+b*b);
						if (fabs(sint)>1.0+EPS)
						{
							sint = (b*c+sqrt(b*b*c*c-(a*a+b*b)*(c*c-a*a)))/(a*a+b*b);
						}
						if (fabs(sint)>1.0+EPS)
							flag=true;
						r=(x21*x21+y21*y21-d21*d21)/(2*(x21*cost+y21*sint+d21));
						if (fabs(x21*cost+y21*sint+d21)<EPS)
							flag=true;
						if (flag)
						{
							flag=false;
							{
								tx=x3;
								ty=y3;
								tt=t3;
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

							if (fabs(a*a+b*b)<EPS)
								flag=true;
							delta=a*a*c*c-(a*a+b*b)*(c*c-b*b);
							if (fabs(delta)<EPS)
								delta=0;
							cost=(a*c-sqrt(delta))/(a*a+b*b);

							if (fabs(cost)>1.0+EPS)
							{
								cost = (a*c+sqrt(a*a*c*c-(a*a+b*b)*(c*c-b*b)))/(a*a+b*b);
							}
							if (fabs(cost)>1.0+EPS)
								flag=true;
							delta=b*b*c*c-(a*a+b*b)*(c*c-a*a);
							if (fabs(delta)<EPS)
								delta=0;
							sint = (b*c-sqrt(delta))/(a*a+b*b);
							if (fabs(sint)>1.0+EPS)
							{
								sint = (b*c+sqrt(b*b*c*c-(a*a+b*b)*(c*c-a*a)))/(a*a+b*b);
							}
							if (fabs(sint)>1.0+EPS)
								flag=true;
							r=(x21*x21+y21*y21-d21*d21)/(2*(x21*cost+y21*sint+d21));
							if (fabs(x21*cost+y21*sint+d21)<EPS)
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

								if (fabs(a*a+b*b)<EPS)
									flag=true;
								delta=a*a*c*c-(a*a+b*b)*(c*c-b*b);
								if (fabs(delta)<EPS)
									delta=0;
								cost=(a*c-sqrt(delta))/(a*a+b*b);

								if (fabs(cost)>1.0+EPS)
								{
									cost = (a*c+sqrt(a*a*c*c-(a*a+b*b)*(c*c-b*b)))/(a*a+b*b);
								}
								if (fabs(cost)>1.0+EPS)
									flag=true;
								delta=b*b*c*c-(a*a+b*b)*(c*c-a*a);
								if (fabs(delta)<EPS)
									delta=0;
								sint = (b*c-sqrt(delta))/(a*a+b*b);
								if (fabs(sint)>1.0+EPS)
								{
									sint = (b*c+sqrt(b*b*c*c-(a*a+b*b)*(c*c-a*a)))/(a*a+b*b);
								}
								if (fabs(sint)>1.0+EPS)
									flag=true;
								r=(x21*x21+y21*y21-d21*d21)/(2*(x21*cost+y21*sint+d21));
								if (fabs(x21*cost+y21*sint+d21)<EPS)
									flag=true;
							}
						}
					}
				}
			}
			x=r*cost+x1;
			y=r*sint+y1;
			if (fabs(x)<EPS)
				x=0.0;
			if (fabs(y)<EPS)
				y=0.0;
		}

		T1=sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1))/C;
		T2=sqrt((x-x2)*(x-x2)+(y-y2)*(y-y2))/C;
		T3=sqrt((x-x3)*(x-x3)+(y-y3)*(y-y3))/C;
		if (T1<t1-EPS || T2<t2-EPS||T3<t3-EPS)
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

			if (fabs(a*a+b*b)<EPS)
				flag=true;
			delta=a*a*c*c-(a*a+b*b)*(c*c-b*b);
			if (fabs(delta)<EPS)
				delta=0;
			cost=(a*c-sqrt(delta))/(a*a+b*b);

			if (fabs(cost)>1.0+EPS)
			{
				cost = (a*c+sqrt(a*a*c*c-(a*a+b*b)*(c*c-b*b)))/(a*a+b*b);
			}
			if (fabs(cost)>1.0+EPS)
				flag=true;
			delta=b*b*c*c-(a*a+b*b)*(c*c-a*a);
			if (fabs(delta)<EPS)
				delta=0;
			sint = (b*c+sqrt(delta))/(a*a+b*b);
			if (fabs(sint)>1.0+EPS)
			{
				sint = (b*c-sqrt(b*b*c*c-(a*a+b*b)*(c*c-a*a)))/(a*a+b*b);
			}
			if (fabs(sint)>1.0+EPS)
				flag=true;
			r=(x21*x21+y21*y21-d21*d21)/(2*(x21*cost+y21*sint+d21));
			if (fabs(x21*cost+y21*sint+d21)<EPS)
				flag=true;
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

				if (fabs(a*a+b*b)<EPS)
					flag=true;
				delta=a*a*c*c-(a*a+b*b)*(c*c-b*b);
				if (fabs(delta)<EPS)
					delta=0;
				cost=(a*c-sqrt(delta))/(a*a+b*b);

				if (fabs(cost)>1.0+EPS)
				{
					cost = (a*c+sqrt(a*a*c*c-(a*a+b*b)*(c*c-b*b)))/(a*a+b*b);
				}
				if (fabs(cost)>1.0+EPS)
					flag=true;
				delta=b*b*c*c-(a*a+b*b)*(c*c-a*a);
				if (fabs(delta)<EPS)
					delta=0;
				sint = (b*c+sqrt(delta))/(a*a+b*b);
				if (fabs(sint)>1.0+EPS)
				{
					sint = (b*c-sqrt(b*b*c*c-(a*a+b*b)*(c*c-a*a)))/(a*a+b*b);
				}
				if (fabs(sint)>1.0+EPS)
					flag=true;
				r=(x21*x21+y21*y21-d21*d21)/(2*(x21*cost+y21*sint+d21));
				if (fabs(x21*cost+y21*sint+d21)<EPS)
					flag=true;
				if (flag)
				{
					flag=false;
					{
						tx=x2;
						ty=y2;
						tt=t2;
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

					if (fabs(a*a+b*b)<EPS)
						flag=true;
					delta=a*a*c*c-(a*a+b*b)*(c*c-b*b);
					if (fabs(delta)<EPS)
						delta=0;
					cost=(a*c-sqrt(delta))/(a*a+b*b);

					if (fabs(cost)>1.0+EPS)
					{
						cost = (a*c+sqrt(a*a*c*c-(a*a+b*b)*(c*c-b*b)))/(a*a+b*b);
					}
					if (fabs(cost)>1.0+EPS)
						flag=true;
					delta=b*b*c*c-(a*a+b*b)*(c*c-a*a);
					if (fabs(delta)<EPS)
						delta=0;
					sint = (b*c+sqrt(delta))/(a*a+b*b);
					if (fabs(sint)>1.0+EPS)
					{
						sint = (b*c-sqrt(b*b*c*c-(a*a+b*b)*(c*c-a*a)))/(a*a+b*b);
					}
					if (fabs(sint)>1.0+EPS)
						flag=true;
					r=(x21*x21+y21*y21-d21*d21)/(2*(x21*cost+y21*sint+d21));
					if (fabs(x21*cost+y21*sint+d21)<EPS)
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

						if (fabs(a*a+b*b)<EPS)
							flag=true;
						delta=a*a*c*c-(a*a+b*b)*(c*c-b*b);
						if (fabs(delta)<EPS)
							delta=0;
						cost=(a*c-sqrt(delta))/(a*a+b*b);

						if (fabs(cost)>1.0+EPS)
						{
							cost = (a*c+sqrt(a*a*c*c-(a*a+b*b)*(c*c-b*b)))/(a*a+b*b);
						}
						if (fabs(cost)>1.0+EPS)
							flag=true;
						delta=b*b*c*c-(a*a+b*b)*(c*c-a*a);
						if (fabs(delta)<EPS)
							delta=0;
						sint = (b*c+sqrt(delta))/(a*a+b*b);
						if (fabs(sint)>1.0+EPS)
						{
							sint = (b*c-sqrt(b*b*c*c-(a*a+b*b)*(c*c-a*a)))/(a*a+b*b);
						}
						if (fabs(sint)>1.0+EPS)
							flag=true;
						r=(x21*x21+y21*y21-d21*d21)/(2*(x21*cost+y21*sint+d21));
						if (fabs(x21*cost+y21*sint+d21)<EPS)
							flag=true;
						if (flag)
						{
							flag=false;
							{
								tx=x3;
								ty=y3;
								tt=t3;
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

							if (fabs(a*a+b*b)<EPS)
								flag=true;
							delta=a*a*c*c-(a*a+b*b)*(c*c-b*b);
							if (fabs(delta)<EPS)
								delta=0;
							cost=(a*c-sqrt(delta))/(a*a+b*b);

							if (fabs(cost)>1.0+EPS)
							{
								cost = (a*c+sqrt(a*a*c*c-(a*a+b*b)*(c*c-b*b)))/(a*a+b*b);
							}
							if (fabs(cost)>1.0+EPS)
								flag=true;
							delta=b*b*c*c-(a*a+b*b)*(c*c-a*a);
							if (fabs(delta)<EPS)
								delta=0;
							sint = (b*c+sqrt(delta))/(a*a+b*b);
							if (fabs(sint)>1.0+EPS)
							{
								sint = (b*c-sqrt(b*b*c*c-(a*a+b*b)*(c*c-a*a)))/(a*a+b*b);
							}
							if (fabs(sint)>1.0+EPS)
								flag=true;
							r=(x21*x21+y21*y21-d21*d21)/(2*(x21*cost+y21*sint+d21));
							if (fabs(x21*cost+y21*sint+d21)<EPS)
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

								if (fabs(a*a+b*b)<EPS)
									flag=true;
								delta=a*a*c*c-(a*a+b*b)*(c*c-b*b);
								if (fabs(delta)<EPS)
									delta=0;
								cost=(a*c-sqrt(delta))/(a*a+b*b);

								if (fabs(cost)>1.0+EPS)
								{
									cost = (a*c+sqrt(a*a*c*c-(a*a+b*b)*(c*c-b*b)))/(a*a+b*b);
								}
								if (fabs(cost)>1.0+EPS)
									flag=true;
								delta=b*b*c*c-(a*a+b*b)*(c*c-a*a);
								if (fabs(delta)<EPS)
									delta=0;
								sint = (b*c+sqrt(delta))/(a*a+b*b);
								if (fabs(sint)>1.0+EPS)
								{
									sint = (b*c-sqrt(b*b*c*c-(a*a+b*b)*(c*c-a*a)))/(a*a+b*b);
								}
								if (fabs(sint)>1.0+EPS)
									flag=true;
								r=(x21*x21+y21*y21-d21*d21)/(2*(x21*cost+y21*sint+d21));
								if (fabs(x21*cost+y21*sint+d21)<EPS)
									flag=true;
							}
						}
					}
				}
			}
			x=r*cost+x1;
			y=r*sint+y1;
			if (fabs(x)<EPS)
				x=0.0;
			if (fabs(y)<EPS)
				y=0.0;
		}

		T1=sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1))/C;
		T2=sqrt((x-x2)*(x-x2)+(y-y2)*(y-y2))/C;
		T3=sqrt((x-x3)*(x-x3)+(y-y3)*(y-y3))/C;
		if (T1<t1-EPS || T2<t2-EPS||T3<t3-EPS)
		{
			while(1);
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

			if (fabs(a*a+b*b)<EPS)
				flag=true;
			delta=a*a*c*c-(a*a+b*b)*(c*c-b*b);
			if (fabs(delta)<EPS)
				delta=0;
			cost=(a*c-sqrt(delta))/(a*a+b*b);

			if (fabs(cost)>1.0+EPS)
			{
				cost = (a*c+sqrt(a*a*c*c-(a*a+b*b)*(c*c-b*b)))/(a*a+b*b);
			}
			if (fabs(cost)>1.0+EPS)
				flag=true;
			delta=b*b*c*c-(a*a+b*b)*(c*c-a*a);
			if (fabs(delta)<EPS)
				delta=0;
			sint = (b*c-sqrt(delta))/(a*a+b*b);
			if (fabs(sint)>1.0+EPS)
			{
				sint = (b*c+sqrt(b*b*c*c-(a*a+b*b)*(c*c-a*a)))/(a*a+b*b);
			}
			if (fabs(sint)>1.0+EPS)
				flag=true;
			r=(x21*x21+y21*y21-d21*d21)/(2*(x21*cost+y21*sint+d21));
			if (fabs(x21*cost+y21*sint+d21)<EPS)
				flag=true;
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

				if (fabs(a*a+b*b)<EPS)
					flag=true;
				delta=a*a*c*c-(a*a+b*b)*(c*c-b*b);
				if (fabs(delta)<EPS)
					delta=0;
				cost=(a*c-sqrt(delta))/(a*a+b*b);

				if (fabs(cost)>1.0+EPS)
				{
					cost = (a*c+sqrt(a*a*c*c-(a*a+b*b)*(c*c-b*b)))/(a*a+b*b);
				}
				if (fabs(cost)>1.0+EPS)
					flag=true;
				delta=b*b*c*c-(a*a+b*b)*(c*c-a*a);
				if (fabs(delta)<EPS)
					delta=0;
				sint = (b*c-sqrt(delta))/(a*a+b*b);
				if (fabs(sint)>1.0+EPS)
				{
					sint = (b*c+sqrt(b*b*c*c-(a*a+b*b)*(c*c-a*a)))/(a*a+b*b);
				}
				if (fabs(sint)>1.0+EPS)
					flag=true;
				r=(x21*x21+y21*y21-d21*d21)/(2*(x21*cost+y21*sint+d21));
				if (fabs(x21*cost+y21*sint+d21)<EPS)
					flag=true;
				if (flag)
				{
					flag=false;
					{
						tx=x2;
						ty=y2;
						tt=t2;
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

					if (fabs(a*a+b*b)<EPS)
						flag=true;
					delta=a*a*c*c-(a*a+b*b)*(c*c-b*b);
					if (fabs(delta)<EPS)
						delta=0;
					cost=(a*c-sqrt(delta))/(a*a+b*b);

					if (fabs(cost)>1.0+EPS)
					{
						cost = (a*c+sqrt(a*a*c*c-(a*a+b*b)*(c*c-b*b)))/(a*a+b*b);
					}
					if (fabs(cost)>1.0+EPS)
						flag=true;
					delta=b*b*c*c-(a*a+b*b)*(c*c-a*a);
					if (fabs(delta)<EPS)
						delta=0;
					sint = (b*c-sqrt(delta))/(a*a+b*b);
					if (fabs(sint)>1.0+EPS)
					{
						sint = (b*c+sqrt(b*b*c*c-(a*a+b*b)*(c*c-a*a)))/(a*a+b*b);
					}
					if (fabs(sint)>1.0+EPS)
						flag=true;
					r=(x21*x21+y21*y21-d21*d21)/(2*(x21*cost+y21*sint+d21));
					if (fabs(x21*cost+y21*sint+d21)<EPS)
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

						if (fabs(a*a+b*b)<EPS)
							flag=true;
						delta=a*a*c*c-(a*a+b*b)*(c*c-b*b);
						if (fabs(delta)<EPS)
							delta=0;
						cost=(a*c-sqrt(delta))/(a*a+b*b);

						if (fabs(cost)>1.0+EPS)
						{
							cost = (a*c+sqrt(a*a*c*c-(a*a+b*b)*(c*c-b*b)))/(a*a+b*b);
						}
						if (fabs(cost)>1.0+EPS)
							flag=true;
						delta=b*b*c*c-(a*a+b*b)*(c*c-a*a);
						if (fabs(delta)<EPS)
							delta=0;
						sint = (b*c-sqrt(delta))/(a*a+b*b);
						if (fabs(sint)>1.0+EPS)
						{
							sint = (b*c+sqrt(b*b*c*c-(a*a+b*b)*(c*c-a*a)))/(a*a+b*b);
						}
						if (fabs(sint)>1.0+EPS)
							flag=true;
						r=(x21*x21+y21*y21-d21*d21)/(2*(x21*cost+y21*sint+d21));
						if (fabs(x21*cost+y21*sint+d21)<EPS)
							flag=true;
						if (flag)
						{
							flag=false;
							{
								tx=x3;
								ty=y3;
								tt=t3;
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

							if (fabs(a*a+b*b)<EPS)
								flag=true;
							delta=a*a*c*c-(a*a+b*b)*(c*c-b*b);
							if (fabs(delta)<EPS)
								delta=0;
							cost=(a*c-sqrt(delta))/(a*a+b*b);

							if (fabs(cost)>1.0+EPS)
							{
								cost = (a*c+sqrt(a*a*c*c-(a*a+b*b)*(c*c-b*b)))/(a*a+b*b);
							}
							if (fabs(cost)>1.0+EPS)
								flag=true;
							delta=b*b*c*c-(a*a+b*b)*(c*c-a*a);
							if (fabs(delta)<EPS)
								delta=0;
							sint = (b*c-sqrt(delta))/(a*a+b*b);
							if (fabs(sint)>1.0+EPS)
							{
								sint = (b*c+sqrt(b*b*c*c-(a*a+b*b)*(c*c-a*a)))/(a*a+b*b);
							}
							if (fabs(sint)>1.0+EPS)
								flag=true;
							r=(x21*x21+y21*y21-d21*d21)/(2*(x21*cost+y21*sint+d21));
							if (fabs(x21*cost+y21*sint+d21)<EPS)
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

								if (fabs(a*a+b*b)<EPS)
									flag=true;
								delta=a*a*c*c-(a*a+b*b)*(c*c-b*b);
								if (fabs(delta)<EPS)
									delta=0;
								cost=(a*c-sqrt(delta))/(a*a+b*b);

								if (fabs(cost)>1.0+EPS)
								{
									cost = (a*c+sqrt(a*a*c*c-(a*a+b*b)*(c*c-b*b)))/(a*a+b*b);
								}
								if (fabs(cost)>1.0+EPS)
									flag=true;
								delta=b*b*c*c-(a*a+b*b)*(c*c-a*a);
								if (fabs(delta)<EPS)
									delta=0;
								sint = (b*c-sqrt(delta))/(a*a+b*b);
								if (fabs(sint)>1.0+EPS)
								{
									sint = (b*c+sqrt(b*b*c*c-(a*a+b*b)*(c*c-a*a)))/(a*a+b*b);
								}
								if (fabs(sint)>1.0+EPS)
									flag=true;
								r=(x21*x21+y21*y21-d21*d21)/(2*(x21*cost+y21*sint+d21));
								if (fabs(x21*cost+y21*sint+d21)<EPS)
									flag=true;
							}
						}
					}
				}
			}
			x=r*cost+x1;
			y=r*sint+y1;
			if (fabs(x)<EPS)
				x=0.0;
			if (fabs(y)<EPS)
				y=0.0;
		}
		//cout<<T1<<' '<<T2<<' '<<T3<<endl;
		printf("Case %d:\n",cnt++);
		if (fabs(x)<EPS)
			printf("0.000000 ");
		else printf("%.6lf ",x);
		if (fabs(y)<EPS)
			printf("0.000000\n");
		else printf("%.6lf\n",y);
	}
}
