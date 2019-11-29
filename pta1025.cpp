
#include <bits/stdc++.h>                      //导入万能库
#define MAX 501                             
#define INF 0x7fffffff                     
using namespace std;
struct node{
    string id;
    int score;
    int t_rank;
    int l_rank;
    int l_num;
};
int money[25];


vector<node>ans;

bool cmp(node a,node b)
{
    if(a.score!=b.score)
        return a.score>b.score;
    return a.id<b.id;
}
double com_fee(string ear,string str);
int main(void)
{
    
    int n,num,pos=1;cin>>n;
    node tem;int pre=0;
    
    for(int i=0;i<n;++i)
    {
        cin>>num;
        pos=1;
        for(int j=0;j<num;++j)
        {
            cin>>tem.id>>tem.score;
            tem.l_num=i+1;
            ans.push_back(tem);
        }
        sort(ans.begin()+pre,ans.begin()+pre+num,cmp);
        ans[0+pre].l_rank=1;
        for(int j=1;j<num;++j)
        {
            if(ans[j+pre].score!=ans[j-1+pre].score)
            {
                ans[j+pre].l_rank=j+1;
                pos=j+1;
            }
            else
            {
                ans[j+pre].l_rank=pos;
            }
        }
        pre+=num;
    }


    sort(ans.begin(),ans.end(),cmp); 
    ans[0].t_rank=1;
    pos=1;
    for(int i=1;i<ans.size();++i)
    {
        if(ans[i].score!=ans[i-1].score)
        {
            ans[i].t_rank=i+1;
            pos=i+1;
        }
        else
        {
            ans[i].t_rank=pos;
        }
    }
    
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();++i)
    {
        cout<<ans[i].id<<" "<<ans[i].t_rank<<" "<<ans[i].l_num<<" "<<ans[i].l_rank<<endl;
    }
    return 0;
}

