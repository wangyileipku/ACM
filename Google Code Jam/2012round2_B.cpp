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
#define ERREQ(X,Y) (fabs((X)-(Y))<EPS)
#define DBGL cout << "here" << endl;

const double PI = acos(-1.0);
const double EPS = 1E-9;
const int INF = (int)1E9;

using namespace std;

int N;
int x[2005];
double p;
double a[2005];

int main(){
	int cs;

	FILE_W("outputB");
	
	cin>>cs;

	for(int csn=1;csn<=cs;csn++){
		printf("Case #%d: ", csn);
		cin >> N;
		FOR(i, N-1) {
			cin >> x[i];
			x[i]--;
		}
		FOR(i, N) a[i] = -INF;
		double h = 100;
		int hidx = -1;
		stack<int> his;
		p = 1.0;
		bool revflag = 0;
		FOR(i, N-1){
			if(hidx==-1){
				hidx = x[i];
				a[i] = a[hidx] = h;
				h--;
			}
			else if(hidx==i){
				h = a[i];
				if(!his.empty()){
					hidx = his.top();
					his.pop();
				}else{
					hidx = -1;
				}
				revflag = 1;
				i--;
			}
			else if(hidx==x[i]){
				a[i] = h;
			}
			else if(x[i]>hidx){
				goto fail;
			}
			else if(x[i]<hidx){
				double didx = x[i]-i;
				double dh = a[hidx] - h;
				double didxall = hidx - i;

				/*
				if(revflag){
					revflag = 0;
					double d = a[i] - (h-(dh/didx*didxn));
					FOR(j, i) a[j] -= d;
				}
				*/
				a[x[i]] = dh/didxall*didx+h;
				a[i] = h;

				double partial = dh/didxall*didx;
				if((int)partial!=partial){
					p *= didxall;
				}
				his.push(hidx);
				hidx = x[i];
			}
		}

		double minh = INF;
		FOR(i, N) minh = min(a[i], minh);
		if(minh<0) FOR(i, N) a[i]-=minh;
		FOR(i, N) a[i] *= p;

		FOR(i, N-1){
			double maxk = -1;
			int high = -1;
			FORST(j, i+1, N-1){
				double k = (double)(a[j]-a[i])/(j-i);
				if(k>maxk){
					maxk = k;
					high = j;
				}
			}
			if(high!=x[i]){
				cout << "ERR " << csn << endl;
			}
		}
		

		FOR(i, N) cout << a[i] << " ";
		cout << endl;
		continue;
fail:
		cout << "Impossible\n";
	}
	return 0;
}
