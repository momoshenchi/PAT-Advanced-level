
#include <bits/stdc++.h>                      //导入万能库
#define MAX 101                             
#define INF 0x7fffffff                     
using namespace std;
struct node{
    string come_time;
    string strat_time;
    int play;
    int vip;
    friend bool operator <(node a,node b)
    {
        return a.come_time>b.come_time;
    }
};

struct position{                      //桌子
    string end_time;
    int id;
    int vip;
    int num;
    friend bool operator <(position a,position b)
    {
        return a.end_time>b.end_time;
    }
};
int num_table;

vector<int>num_t;
vector<node>ans;
vector<position>table;
bool cmp(node a,node b)
{
    return a.come_time<b.come_time;
}
string time_add(string tem,int during);
int  s_ptime(string s1,string s2);
set<node> ::iterator v_wait(set<node>&q);
int main(void)
{
    
    int n,num,pos=1;cin>>n;
    node tem;int pre=0;
    
    for(int i=0;i<n;++i)
    { 
        cin>>tem.come_time>>tem.play>>tem.vip;
        ans.push_back(tem);
    }

    int num_vip;
    cin>>num_table>>num_vip;
    table.resize(num_table+1);
    num_t.resize(num_table+1);
    for(int i=0;i<num_vip;++i)
    {
        cin>>pre;
        table[pre].vip=true;
    }
    for(int i=0;i<num_table;++i)
    {
        table[i].id=i+1;
    }
    sort(ans.begin(),ans.end(),cmp);

    //initialization
    priority_queue<position>deq;                //table queue
    set<node>wait;                    //member queue
    int flag=1;
   // position temp;
    int k=0;
    while (deq.size()<num_table)
    {
        ans[k].strat_time=ans[k].come_time;
        table[k].end_time=time_add(ans[k].come_time,ans[k].play);
        num_t[table[k].id]++;
        cout<<ans[k].come_time<<" "<<ans[k].strat_time<<" "<<0<<endl;
        deq.push(table[k++]);                                  //初始化,把桌子放满
    }
    
    node ss;position s;
    // ac
                                 //设置一个优先队列(享受队列),他是一个进,一个出正好符合.但时间小在前面
    for(int i=k;i<ans.size();++i)
    {
        if(ans[i].come_time<=deq.top().end_time &&deq.top().end_time<"21:00:00")
        {
            wait.insert(ans[i]);
        }     
                                                              //wei dui 21:00 bianjie panduan
        else  if(deq.top().end_time<"21:00:00" &&!wait.empty())     //wait排出一个人,继续上面流程
        {
            if(deq.top().vip &&v_wait(wait)!=wait.end())                 
            {
                ss=*v_wait(wait);
                wait.erase(v_wait(wait));
                                                 //等待的还要观察后面是否有vip,是否有vip桌子
            }
            else  
            {
                ss=*wait.begin();
                wait.erase(wait.begin());
            }
            ss.strat_time=deq.top().end_time;
            s=deq.top();
            deq.pop();
            s.end_time=time_add(ss.strat_time,ss.play);
            num_t[s.id]++;
            cout<<ss.come_time<<" "<<ss.strat_time<<" "<<s_ptime(ss.strat_time,ss.come_time)<<endl;
            deq.push(s);   
            i--;    
        }
        
        else if(!deq.empty()&& wait.empty()&&deq.top().end_time<"21:00:00")
        {
            ss=ans[i];
            ss.strat_time=ss.come_time;
            s=deq.top();
            deq.pop();
            num_t[s.id]++;
            s.end_time=time_add(ss.strat_time,ss.play);
            cout<<ss.come_time<<" "<<ss.strat_time<<" "<<s_ptime(ss.strat_time,ss.come_time)<<endl;
            deq.push(s);
        }
    }
    for(int i=1;i<=num_table;++i)
    {
        if(i!=1)
        cout<<" ";
        cout<<num_t[i];
    }

    return 0;
}
// accomplish
string time_add(string tem,int during){

    string str;
    str=tem;
    int minute=stoi(tem.substr(3,2));
    minute+=during;
    
    if(minute>=60)
    {
        int hour=stoi(tem.substr(0,2));
        hour+=minute/60;
        minute%=60;
        ostringstream term;
        term<<hour;    
        str.replace(0,2,term.str());
    }
    ostringstream term;
    term<<minute;    
    str.replace(3,2,term.str());
    return str;
}
set<node>:: iterator v_wait(set<node>&q)                       //判断队列中是否有vip,有返回编号+1,没有返回0
{   auto i=q.begin();
    for(;i!=q.end();++i)
    {
        if(i->vip==1)
            return i;
    }
    return i;
}
int  s_ptime(string s1,string s2)                         //时间相减后四舍五入
{
    int sum=0;
   
    sum+=(stoi(s1.substr(0,2))-stoi(s2.substr(0,2)))*60;
    sum+=(stoi(s1.substr(3,2))-stoi(s2.substr(3,2)));
    sum+=round((stoi(s1.substr(6,2))-stoi(s2.substr(6,2)))/60.0);
    return sum;
}