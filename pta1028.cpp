
#include <bits/stdc++.h>                      //导入万能库
#define MAX 101                             
#define INF 0x7fffffff                     
using namespace std;
struct node{
    string id;
    string name;
    int score;
};

vector<node>ans;
bool cmp1(node a,node b)
{
    return a.id<b.id;
}

bool cmp2(node a,node b)
{
    if(a.name!=b.name)
        return a.name<b.name;
    return a.id<b.id;
}

bool cmp3(node a,node b)
{
    if(a.score!=b.score)
        return a.score<b.score;
    return a.id<b.id;
}
int main(void)
{
    
    int n,num,pos=1,type;cin>>n>>type;
    node tem;
    
    for(int i=0;i<n;++i)
    { 
        cin>>tem.id>>tem.name>>tem.score;
        ans.push_back(tem);
    }
    if(type==1)
        sort(ans.begin(),ans.end(),cmp1);
    else if(type==2)
        sort(ans.begin(),ans.end(),cmp2);
    else if(type==3)
        sort(ans.begin(),ans.end(),cmp3);
    
    for(int i=0;i<n;++i)
    {
        cout<<ans[i].id<<" "<<ans[i].name<<" "<<ans[i].score<<endl;
    }
    
}
// accomplish
