#include <bits/stdc++.h>
using namespace std;
const int radix = 13;

vector<string>ans;

int main()
{
    string str;int n,cnt=0;
    cin>>n;string tem;
  
    for(int i=0;i<n;++i)
    {
        cin>>tem;
        ans.push_back(tem);
    }
    string sum="";
    //tihuan
    
    sort(ans.begin(),ans.end(),[=](string a,string b){
        return a+b<b+a;
    });
    
    for(int i=0;i<ans.size();++i)
    {
        sum+=ans[i];
    }
    
    while(sum[0]=='0')
        sum.erase(0,1);
    if(sum.length()==0)
    {
        cout<<0;
        return 0;
    }
    cout<<sum;
	return 0;
}
