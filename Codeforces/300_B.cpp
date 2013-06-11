// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
int father[50];

int find(int i)
{
    if (father[i]!=i)
        return father[i]=find(father[i]);
    return i;
}

void unite(int i,int j)
{
    father[find(i)]=find(j);
}

int main() {
    // Start typing your code here...
    map<int,vector<int> > mymap;
    set<int> myset;
    set<int> single;
    for (int i=0;i<50;i++)
    {
        father[i]=i;
    }
    int n,m;
    cin>>n>>m;
    for (int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        unite(a,b);
    }
    bool flag = true;
    for (int i=1;i<=n;i++)
    {
        int t = find(i);
        //cout<<t<<endl;
        mymap[t].push_back(i);
        myset.insert(t);
    }
    set<int>::iterator it,it2;
    int cnt1=0,cnt2=0;
    for (it=myset.begin();it!=myset.end();it++)
    {
        if (mymap[*it].size()>3)
        {
            flag = false;
            break;
        }
        if (mymap[*it].size()==2)
            cnt2++;
        if (mymap[*it].size()==1)
        {    
            single.insert(*it);
            cnt1++;
        }
    }
    if (!flag || cnt2>cnt1)
        cout<<-1<<endl;
    else
    {
        it2 = single.begin();
        
        for (it=myset.begin();it!=myset.end();it++)
        {
            if (mymap[*it].size()==3)
            {
                cout<<mymap[*it][0]<<' '<<mymap[*it][1]<<' '<<mymap[*it][2]<<endl;
            }
            else if (mymap[*it].size()==2)
            {
                cout<<mymap[*it][0]<<' '<<mymap[*it][1]<<' '<<(*it2)<<endl;
                it2++;
            }
        }
        
        for (;it2!=single.end();)
        {
            cout<<(*it2)<<' ';
            it2++;
            cout<<(*it2)<<' ';
            it2++;
            cout<<(*it2)<<endl;
            it2++;
        }
    }
    
    return 0;
}