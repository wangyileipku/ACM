//#include <iostream>
//using namespace std;
//double p[201],v[201],leftdist[201],rightdist[201];
//class Range
//{
//public:
//	double left;
//	double right;
//};
//Range range[201];
//int main()
//{
//	int t,c,d;
//	cin>>t;
//	for (int i=1;i<=t;i++)
//	{
//		memset(p,0,sizeof(p));
//		memset(v,0,sizeof(v));
//		memset(dist,0,sizeof(dist));
//		cin>>c>>d;
//		for (int j=0;j<c;j++)
//		{
//			cin>>p[j]>>v[j];
//			double temp=(v[j]-1)*1.0/2*d;
//			range[j].left = p[j]-temp;
//			range[j].right = p[j]+temp;
//			leftdist[j]=rightdist[j]=temp;
//		}
//		bool flag=1;
//		while(flag)
//		{
//			flag=0;
//			for (int j=0;j<c-1;j++)
//			{
//				if (range[j].right>range[j+1].left-d)
//				{
//					flag=1;
//				}
//			}
//		}
//		cout<<"Case #"<<i<<":"<<endl;
//	}
//	return 0;
//}