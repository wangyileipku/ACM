#include <iostream>
using namespace std;
int x[100005];
int y[100005];
int width = 28;
int height = 15;
bool init(int fx,int fy,int x1,int y1,int x2,int y2)
{
	if (fx > x1 && fx < x2 && fy > y1 && fy < y2)
		return true;
	else return false;
}
bool notinter(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)
{
	if (x1 >= x4 || x2 <= x3 || y1 >= y4 || y2 <= y3)
		return true;
	else return false;
}
int main()
{
	int a,b,n;
	int firstlastx,firstlasty,secondlastx,secondlasty;
	int cnt,mincnt;
	cin>>a>>b;
	while (a!=0 || b!=0)
	{
		cin>>n;
		mincnt = 10000000;
		for (int i=0;i<n;i++)
			cin>>x[i]>>y[i];
		for (int firstx = 0; firstx + height <= a;firstx ++)
			for (int firsty = 0;firsty + height <=b ;firsty ++)
				for (int firstd = 0; firstd < 2;firstd ++)
				{
					if (firstd == 0)
					{
						firstlastx = firstx + height;
						firstlasty = firsty + width;
					}
					else
					{
						firstlastx = firstx + width;
						firstlasty = firsty + height;
					}
					if ( (firstlastx > a) || (firstlasty > b))
						continue;
					for (int secondx = 0; secondx + height <= a;secondx ++)
						for (int secondy = 0;secondy + height <=b ;secondy ++)
							for (int secondd = 0; secondd < 2;secondd ++)
							{
								if (secondd == 0)
								{
									secondlastx = secondx + height;
									secondlasty = secondy + width;
								}
								else
								{
									secondlastx = secondx + width;
									secondlasty = secondy + height;
								}
								if (secondlastx > a ||secondlasty > b)
									continue;
								if (!notinter(secondx,secondy,secondlastx,secondlasty,firstx,firsty,firstlastx,firstlasty) || init((secondx+secondlastx)/2,(secondy+secondlasty)/2,firstx,firsty,firstlastx,firstlasty) || init((firstx+firstlastx)/2,(firsty+firstlasty)/2,secondx,secondy,secondlastx,secondlasty) || init(secondx,secondy,firstx,firsty,firstlastx,firstlasty) || init(firstx,firsty,secondx,secondy,secondlastx,secondlasty) || init(secondlastx,secondlasty,firstx,firsty,firstlastx,firstlasty) || init(firstlastx,firstlasty,secondx,secondy,secondlastx,secondlasty))
									continue;
								cnt = 0;
								for (int i=0;i<n;i++)
								{
									if (init(x[i],y[i],firstx,firsty,firstlastx,firstlasty) || init(x[i],y[i],secondx,secondy,secondlastx,secondlasty) )
										cnt ++;
								}
								if (cnt < mincnt)
								{
//									cout<<cnt<<' '<<firstx<<' '<<firsty<<' '<<firstlastx<<' '<<firstlasty<<' '<<firstd<<' '<<secondx<<' '<<secondy<<' '<<secondlastx<<' '<<secondlasty<<' '<<secondd<<endl;
									mincnt = cnt;
								}
							}
				}
		cout<<mincnt<<endl;
		cin>>a>>b;
	}
	return 0;
}