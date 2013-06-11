#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <utility>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <list>
#include <time.h>
#include <stdio.h>

#define FORST(X,S,T) for(int X=S; X<=T; X++)  
#define RFORST(X,S,T) for(int X=S; X>=T; X--)  
#define FOR(X,XB) for(int X=0; X<XB; X++)
#define RFOR(X,XB) for(int X=XB-1; X>=0; X--)
#define FORSTL(X,C) for(X=C.begin();X!=C.end();X++)
#define SQR(X) ((X)*(X))
#define MID(X,Y) ((X+Y)/2)
#define FILL(X,V) memset(X,V,sizeof(X))
#define FILE_R(X) freopen(X, "r", stdin)  
#define FILE_W(X) freopen(X, "w", stdout)  
#define ERREQ(X,Y) fabs(X-Y)<EPS

const double PI = acos(-1.0);
const double EPS = 1E-9;
const int INF = (int)1E9;

using namespace std;

struct Point{
	double x, y;
	Point(){}
	Point(double _x, double _y){ x=_x; y=_y; }
	double dist(Point &p){
		return sqrt(SQR(x-p.x)+SQR(y-p.y));
	}
};
struct Circle{
	double x, y, r;
	Circle(){}
	Circle(double _x, double _y, double _r) { x=_x; y=_y; r=_r; }
	double dist(Circle &c){
		return Point(x,y).dist(Point(c.x,c.y));
	}
	double dist(Point &p){
		return Point(x,y).dist(p);
	}
};

int N;
Circle plant[50];
Point sprinkler[2500];
int cnt;

bool check(double r){
	cnt = 0;
	FOR(i, N) sprinkler[cnt++] = Point(plant[i].x, plant[i].y);
	
	FOR(i, N) FORST(j, i+1, N-1){
		double r1 = r-plant[i].r;
		double r2 = r-plant[j].r;
		double dist = plant[i].dist(plant[j]);
		if(dist>r1+r2+EPS) continue;

		double x1 = plant[i].x, x2 = plant[j].x, y1 = plant[i].y, y2 = plant[j].y;
		double a = 2.0*(x2-x1), b=2.0*(y2-y1), c=SQR(x1)-SQR(x2)+SQR(y1)-SQR(y2)+SQR(r2)-SQR(r1);
		double X1, Y1, X2, Y2;
		if(fabs(x1-x2)>fabs(y1-y2)){
			double A = SQR(a)+SQR(b);
			double B = 2.0*(b*c+a*b*x1-y1*SQR(a));
			double C = SQR(c)+2.0*a*x1*c+SQR(a)*(SQR(x1)+SQR(y1)-SQR(r1));
			double Delta = SQR(B)-4.0*A*C;
			if(Delta>0+EPS){
				Y1 = (-B+sqrt(Delta))/2.0/A;
				X1 = (-b*Y1-c)/a;
				Y2 = (-B-sqrt(Delta))/2.0/A;
				X2 = (-b*Y2-c)/a;
				sprinkler[cnt++] = Point(X1, Y1);
				sprinkler[cnt++] = Point(X2, Y2);
			}
		}else{
			double A = SQR(a)+SQR(b);
			double B = 2.0*(a*c+a*b*y1-x1*SQR(b));
			double C = SQR(c)+2.0*b*y1*c+SQR(b)*(SQR(x1)+SQR(y1)-SQR(r1));
			double Delta = SQR(B)-4.0*A*C;
			if(Delta>0+EPS){
				X1 = (-B+sqrt(Delta))/2.0/A;
				Y1 = (-a*X1-c)/b;
				X2 = (-B-sqrt(Delta))/2.0/A;
				Y2 = (-a*X2-c)/b;
				sprinkler[cnt++] = Point(X1, Y1);
				sprinkler[cnt++] = Point(X2, Y2);
			}
		}
	}

	FOR(i, cnt) FORST(j, i+1, cnt-1){
		bool ok = 1;
		FOR(k, N){
			double d1 = plant[k].dist(sprinkler[i]);
			double d2 = plant[k].dist(sprinkler[j]);
			if(d1+plant[k].r>r+EPS && d2+plant[k].r>r+EPS){
				ok = 0;
				break;
			}
		}
		if(ok) return true;
	}
	return false;
}

int main(){
	int cs;
	double lr, rr, mr;

	//FILE_W("output");
	
	cin>>cs;

	for(int csn=1;csn<=cs;csn++){
		printf("Case #%d: ", csn);
		cin>>N;
		FOR(i, N){
			double x, y, r;
			cin >> x >> y >> r;
			plant[i] = Circle(x,y,r);
		}
		lr = 0; rr = 10000;
		while(lr<rr-EPS){
			mr = MID(lr, rr);
			if(check(mr))
				rr = mr;
			else
				lr = mr;
		}
		printf("%.8lf\n", lr);
	}
	return 0;
}