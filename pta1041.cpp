#include <bits/stdc++.h>
using namespace std;

map<int,int>dit;
vector<int>ans;
int main()
{
    string str;
    int n,tem;cin>>n;
    
    for(int i=0;i<n;++i)
    {
        cin>>tem;
        ans.push_back(tem);
        dit[tem]++;
    }
    for(int i=0;i<n;++i)
    {
        if(dit[ans[i]]==1)
        {
            cout<<ans[i];
            return 0;
        }
    }
    cout<<"None";

	return 0;
}