
#include <bits/stdc++.h>                      //导入万能库
#define MAX 501                             
#define INF 0x7fffffff                     
using namespace std;

int money[25];
map<string,map<string,int>>dit;


int main(void)
{
    int radix,num;
    int n;

    for(int i=0;i<24;++i)
    {
        cin>>money[i];
    }

    cin>>n;
    string id,time,state;
    for(int i=0;i<n;++i)
    {
        cin>>id;
        cin>>time>>state;
        if(state=="on-line")
            dit[id][time]=1;
        else
        {
            dit[id][time]=0;
        }
        
    }
    for(auto i=dit.begin();i!=dit.end();++i)
    {
        for(auto j=dit[i->first].begin();j!=dit[i->first].end();++j)
        {

        }

    }
    return 0;
}


