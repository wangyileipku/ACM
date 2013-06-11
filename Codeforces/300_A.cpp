// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Start typing your code here...
    vector<int> ans[3];
    vector<int> a;
    
    bool flag = false;
    int n,tmp;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>tmp;
        a.push_back(tmp);
        if (tmp>0)
            flag = true;
    }
    
    if (flag)
    {
        bool pos = false,neg = false;
        for (int i=0;i<n;i++)
        {
            if (a[i]<0 && neg == false)
            {
                ans[0].push_back(a[i]);
                neg = true;
            }
            else if (a[i]>0 && pos == false)
            {
                ans[1].push_back(a[i]);
                pos = true;
            }
            else ans[2].push_back(a[i]);
        }
    }
    else
    {
        int cnt = 0;
        bool neg = false;
        for (int i=0;i<n;i++)
        {
            if (a[i]<0 && neg == false)
            {
                ans[0].push_back(a[i]);
                neg = true;
            }
            else if (a[i]<0 && cnt<2)
            {
                ans[1].push_back(a[i]);
                cnt++;
            }
            else ans[2].push_back(a[i]);
        }
    }
    
    for (int i=0;i<3;i++)
    {
        cout<<ans[i].size();
        for (int j=0;j<ans[i].size();j++)
        {
            cout<<' '<<ans[i][j];
        }
        cout<<endl;
    }
    
    
    return 0;
}