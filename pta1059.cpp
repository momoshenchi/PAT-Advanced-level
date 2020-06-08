

#include <bits/stdc++.h>                      //导入万能库
#define MAX 501010                             
#define INF 0x7fffffff                     
using namespace std;
bool prime[MAX];
vector<int>primelist;
void get_prime(long long tem);
map<int,int>dit;
int main(void)
{
    
    long long int tem;
    long long int sum;
    cin>>tem;sum=tem;
    get_prime(tem);
    if(tem==1 )
    {
        printf("%lld=%lld",tem,tem);
        return 0;
    }
    
    for(int i=0;i<primelist.size();++i)
    {
        while(tem%primelist[i]==0)
        {
            dit[primelist[i]]++;
            tem/=primelist[i];
        }
    }
    printf("%lld=",sum);
    for(auto i=dit.begin();i!=dit.end();++i)
    {
        if(i!=dit.begin())
        {
            cout<<"*";
        }
        if(i->second>1)
        {
            cout<<i->first<<"^"<<i->second;
        }
        else
            cout<<i->first;
    }
    return 0;
}

void get_prime(long long tem)
{
    if(tem<=1)
        return ;
    for(int i=2;i<=500000;++i)
    {
        if(!prime[i])
        {
            primelist.push_back(i);
            for(int j=i*2;j<=500000;j+=i)
            {
                prime[j]=true;
            }
        }
    }
    return ;
}