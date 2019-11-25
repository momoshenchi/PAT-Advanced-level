
#include <bits/stdc++.h>                      //导入万能库
#define MAX 501                             //set  the maxsize
#define INF 0x7fffffff                      //set  the edge of INF
using namespace std;
map<int,double,greater<int> >dit;
 
int main(void)
{
    
    int tem,n1,n2;
    double b;int a;
    
    cin>>n1;
    for(int i=0;i<n1;++i)
    {
        cin>>a>>b;
        dit[a]+=b;
    }
    cin>>n2;
    for(int i=0;i<n2;++i)
    {
        cin>>a>>b;
        dit[a]+=b;
    }

    for(auto i=dit.begin();i!=dit.end();++i)
    {
        if(i->second==0)
        dit.erase(i);
    }
    cout<<dit.size();
    for(auto i=dit.begin();i!=dit.end();++i)
    {
        printf(" %d %.1f",i->first,i->second);
    }  
    return 0;
}


