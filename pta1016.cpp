
#include <bits/stdc++.h>                      //导入万能库
#define MAX 501                             
#define INF 0x7fffffff                     
using namespace std;
struct node{
    string id;
    string time;
    string state;
};
int money[25];

map<string,vector<node>>dit;
vector<node>ans;

bool cmp(node a,node b)
{
    if(a.id!=b.id)
        return a.id<b.id;
    return a.time<b.time;
}
double com_fee(string ear,string str);
int main(void)
{
    
    int n;
    node tem;

    for(int i=0;i<24;++i)
    {
        cin>>money[i];
        money[24]+=money[i];
    }

    cin>>n;
    string id,time,state;

    for(int i=0;i<n;++i)
    {
        cin>>tem.id>>tem.time>>tem.state;
        ans.push_back(tem);
    }

    sort(ans.begin(),ans.end(),cmp);

    for(int i=1;i<n;++i)
    {
        if(ans[i].id==ans[i-1].id)
        {
            if(ans[i].state=="off-line" &&ans[i-1].state=="on-line")
            {  
                dit[ans[i].id].push_back(ans[i-1]);
                dit[ans[i].id].push_back(ans[i]);
            }
        }
    }
    //dit 甄除不匹配项的个人时间单
    for(auto i=dit.begin();i!=dit.end();++i)
    {
        cout<<i->first<<" "<<i->second[0].time.substr(0,2)<<endl; 
        double sum=0;    
        for(int j=1;j<i->second.size();j+=2)
        {
            sum+=com_fee(i->second[j-1].time,i->second[j].time);
        }
        printf("Total amount: $%.2f\n",sum);
    }
    return 0;
}

double com_fee(string ear,string str)
{

    cout<<ear.substr(3,8)<<" "<<str.substr(3,8)<<" ";

    double sum=0;
    int day=stoi(str.substr(3,2));
    int hour=stoi(str.substr(6,2));
    int minute=stoi(str.substr(9,2));
    sum+=money[24]*60*day+minute*money[hour];
    for(int i=0;i<hour;++i)
    {
        sum+=money[i]*60;
    }
    sum/=100;


    double sum2=0;
    int day2=stoi(ear.substr(3,2));
    int hour2=stoi(ear.substr(6,2));
    int minute2=stoi(ear.substr(9,2));
    sum2+=money[24]*60*day2+minute2*money[hour2];
    for(int i=0;i<hour2;++i)
    {
        sum2+=money[i]*60;
    }
    sum2/=100;


    int total=0;
    total+=day*24*60+hour*60+minute-(day2*24*60+hour2*60+minute2);
    cout<<total<<" ";
    printf("$%.2f\n",sum-sum2);
    return sum-sum2;
}

