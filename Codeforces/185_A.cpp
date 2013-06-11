#include <iostream>
#include <stdio.h>
#include <list>
#include <map>
#include <queue>
#include <cstring>
using namespace std;
int main()
{
	char word[200];
	int n;
	cin>>n;
	cin.getline(word,10);
	while(n--)
	{
		cin.getline(word,200);
		string s(word);
		int sign = 0;
		if (s.find("miao.") == 0)
			sign += 1;
		if (s.rfind("lala.") == s.length() - 5)
			sign += 2;
		if (sign == 1)
			cout<<"Rainbow's"<<endl;
		else if (sign == 2)
			cout<<"Freda's"<<endl;
		else cout<<"OMG>.< I don't know!"<<endl;
	}

	return 0;
}