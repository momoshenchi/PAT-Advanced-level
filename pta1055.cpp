
#include <bits/stdc++.h>                      //导入万能库
#define MAX 101                             
#define INF 0x7fffffff                     
using namespace std;
struct node{
    int  money;
    string name;
    int age;
};
void process(int num,int L,int R);

vector<node>ans;

bool cmp(node a,node b)
{
    if(a.money!=b.money)
        return a.money>b.money;
    else if(a.age!=b.age)
        return a.age<b.age;
    return a.name<b.name;
}

int main(void)
{
    
    int n,num,query;cin>>n>>query;
    node tem;
    
    for(int i=0;i<n;++i)
    { 
        cin>>tem.name>>tem.age>>tem.money;
        ans.push_back(tem);
    }
    int max_num,L,R;
    sort(ans.begin(),ans.end(),cmp);
    for(int j=0;j<query;++j)
    {
        int cnt=0;
        cin>>max_num>>L>>R;
        cout<<"Case #"<<j+1<<":"<<endl;
        for(int i=0;i<ans.size();++i)
        {
            if(ans[i].age>=L && ans[i].age<=R )
            {
                cout<<ans[i].name<<" "<<ans[i].age<<" "<<ans[i].money<<endl;
                cnt++;
            }
            if(cnt==max_num)
                break;
        }
        if(!cnt)
        {
            cout<<"None"<<endl;
        }
    }
    
    return 0;
}
