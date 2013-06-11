/*
ID: wangyil2
PROG: namenum
LANG: C++
*/
/*
Alg: Complete Search(Brute-force)
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <list>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
char c[8][4]={"ABC","DEF","GHI","JKL","MNO","PRS","TUV","WXY"};
char num[25];
int len;
map<string,bool> dict;
bool flag=false;
ofstream fout("namenum.out");
ifstream fin("namenum.in");
ifstream dictin("dict.txt");

class Node
{
public:
	int num;
	char c;
	list<Node> child;
	bool end;
	Node()
	{
	}
	Node(int n_,char c_, bool end_=false)
	{
		num=n_;
		c=c_;
		end = end_;
	}
};

Node root;

int cti(char c)
{
	if (c>'Q')
		c--;
	return (c-'A')/3+2;
}

void createTree(Node &root, int pos)
{
	if (pos==len)
	{
		root.end = true;
		return;
	}
	char cur = num[pos];
	list<Node>::iterator it;
	bool f = false;
	for (it=root.child.begin();it!=root.child.end();it++)
	{
		if (it->c == cur)
		{
			createTree((*it),pos+1);
			f = true;
			break;
		}
	}
	if (!f)
	{
		Node tmp(cti(cur),cur);
		createTree(tmp,pos+1);
		root.child.push_back(tmp);
	}
}
int cnt=0;
void traverse(Node &root,string s)
{
	s+=root.c;
	if (root.end)
	{
		cnt++;
		cout<<s.c_str()<<endl;
		//return ;
	}
	list<Node>::iterator it;

	for (it=root.child.begin();it!=root.child.end();it++)
	{
		traverse(*it,s);
	}

}
bool find(Node &root,string s,int pos)
{
	if (pos!=0)
		s+=root.c;
	if (pos==len)
	{
		if (root.end)
		{
			flag = true;
			fout<<s.c_str()<<endl;
		}
		return true;
	}
	list<Node>::iterator it;

	bool f = false;
	for (it=root.child.begin();it!=root.child.end();it++)
	{
		if (it->num == num[pos])
		{
			f = true;
			find(*it,s,pos+1);
		}
	}
	return f;
}
int main() 
{

	root.c=' ';
	while(dictin>>num)
	{
		len=strlen(num);
		createTree(root,0);
	}
	//traverse(root,"");
	//cout<<cnt<<endl;

	fin>>num;
	len=strlen(num);
	for (int i=0;i<len;i++)
		if (num[i]<'2' || num[i]>'9')
		{
			fout<<"NONE"<<endl;
			return 0;
		}
		else
			num[i] = num[i]-'0';

	find(root,"",0);

	if (!flag)
		fout<<"NONE"<<endl;


	return 0;

}