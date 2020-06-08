#include <bits/stdc++.h>
using namespace std;

unordered_map<int,int>dit;
int main(void)
{
    int max_stack,num,times,tem;
    int m,n;
    cin>>m>>n;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cin>>tem;
            dit[tem]++;
        }
    }
    int max_a=0,pos;
    for(auto i=dit.begin();i!=dit.end();++i)
    {
        if(i->second>max_a)
        {
            max_a=i->second;
            pos=i->first;
        }
    }
    
    cout<<pos;
	return 0;
}

