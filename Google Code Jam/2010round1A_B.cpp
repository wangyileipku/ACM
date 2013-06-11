#include <iostream>
using namespace std;
int a[260];
int t,D,I,M,N,result;
int main()
{

	cin>>t;
	for (int i=1;i<t;i++)
	{
		memset(a,0,sizeof(a));
		cin>>D>>I>>M>>N;
		for (int j=0;j<N;j++)
			cin>>a[j];

		cout<<"Case #"<<i<<": "<<result;
	}
}