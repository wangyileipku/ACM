#include "stdio.h"
#include "iostream"
#include "string"
#include "iomanip"
#include "cmath"
#include "memory.h"
#include "algorithm"
#include "vector"
#include "queue"
#include "map"
#include "list"
#include "set"
using namespace std;
map<string,bool> fea;
map<int,string> branch;
vector<int> son[500];
double w[500];
int father[500];
char c[200][200];
int index=1;
bool f[500];
void init(int now)
{
	double wei;
	char x;
	while(x=cin.peek ())
	{
		if (x==' '||x=='\n') 
		{
			cin.ignore ();
			continue;
		}
		if (x=='(')
		{
			if (w[now]==0)
			{
				cin.ignore ();
				cin>>wei;
				w[now]=wei;
				char y;
				char name[100]={};
				int ind=0;
				bool hasname=0;
				while(y=cin.peek())
				{
					if (y=='('||y==')')
						break;
					if (y>='a'&&y<='z')
					{
						hasname=1;
						while(y>='a'&&y<='z')
						{
							name[ind++]=y;
							cin.ignore ();
							y=cin.peek ();
						}
						name[ind]=0;
						break;
					}
					cin.ignore ();
				}
				if (hasname)
				{
					string sname=name;
					branch[index]=sname;
					son[now].push_back (index);
					f[index]=1;
					index++;
					init(index);
				}
				else
				{
					if (y=='(')
					{
						son[now].push_back (index);
						init(index++);
					}
					else if (y==')')
					{
						cin.ignore ();
						return ;
					}
				}
			}
			else
			{
				son[now].push_back (index);
				cin.ignore ();
				cin>>wei;
				w[index]=wei;
				index++;
				char y;
				while(y=cin.peek ())
				{
					cin.ignore ();
					if (y==')')
						break ;
				}
			}
			
		}
		else if (x==')')
			return ;
	}
}
void dfs(int id,double &p)
{
	p*=w[id];
	if (f[id]==0) return;
	vector<int>::iterator j;
	for (j=son[id].begin();j!=son[id].end();j++)
	{
		if (fea[branch[*j]])
			dfs(*j,p);
	}
}

int main()
{
	int t,l,n,a;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		memset(father,0,sizeof(father));
		memset(w,0,sizeof(w));
		memset(f,0,sizeof(f));
		for (int j=0;j<500;j++)
			son[j].clear();
		cin>>l;
		index=1;
		string root="root";
		branch[index]=root;
		f[index]=1;
		index++;
		int now=1;
		char x;
		init(now);
		cin>>n;
		cout<<"Case #"<<i<<":"<<endl;
		for (int j=0;j<n;j++)
		{
			string s;
			fea.clear ();
			cin>>s;
			cin>>a;
			for(int k=1;k<=a;k++)
			{
				cin>>s;
				fea[s]=1;
			}
			double p=1.0;
			dfs(1,p);
			cout<<p<<endl;
		}
		

	}	
}