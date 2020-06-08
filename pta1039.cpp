#include <bits/stdc++.h>
using namespace std;
const int radix = 13;
map<string,vector<int>>dit;
vector<string>ans;
void pri(string tem);
int main()
{
    string str;int n,cnt=0,course,num,id;
    cin>>n>>course;string tem;
    for(int i=0;i<course;++i)
    {
        cin>>id>>num;
        for(int j=0;j<num;++j)
        {
            cin>>tem;
            dit[tem].push_back(id);
        }
    }
    for(int i=0;i<n;++i)
    {
        cin>>tem;
        pri(tem);
    }
	return 0;
}


void pri(string tem)
{
    cout<<tem<<" ";
    vector<int>ans;
    for(int i=0;i<dit[tem].size();++i)
    {
        ans.push_back(dit[tem][i]);
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size();
    for(int m:ans)
    {
        cout<<" "<<m;
    }
    cout<<endl;
}