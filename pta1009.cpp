
#include <bits/stdc++.h>                      
#define MAX 501                            
#define INF 0x7fffffff    
using namespace std;
map<int,double,greater<int>>dit1;   
map<int,double,greater<int>>sum;   

int main(void)
{
    
    int now=0,n1,n2;
    int a;double b;

    cin>>n1;
    for(int i=0;i<n1;++i)
    {
        cin>>a>>b;
        dit1[a]+=b;
    }
    cin>>n2;
    for(int i=0;i<n2;++i)
    {
        cin>>a>>b;
        for(auto i=dit1.begin();i!=dit1.end();i++)
        {
            sum[i->first+a]+=i->second*b;
        }
    }

    for(auto i=sum.begin();i!=sum.end();++i)
    {
        if(i->second==0)
            sum.erase(i);
    }

    cout<<sum.size();
    for(auto i=sum.begin();i!=sum.end();++i)
    {
        printf(" %d %.1f",i->first,i->second);
        
    }
    return 0;
}

