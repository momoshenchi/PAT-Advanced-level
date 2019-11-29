
#include <bits/stdc++.h>                      //导入万能库
using namespace std;

struct student{
    string id;
    int score[4];
    int rank[4];
};

int flag=0;
char as[]={'A','C','M','E'};

bool cmp(student a,student b)
{
    return a.score[flag]>b.score[flag];
}
vector<student>ans;
map<string,int>dit;

int main(void)
{
    int num_stu,num_ver;
    student tem;
    cin>>num_stu>>num_ver;

    for(int i=0;i<num_stu;++i)
    {
        cin>>tem.id>>tem.score[1]>>tem.score[2]>>tem.score[3];
        tem.score[0]=(tem.score[1]+tem.score[2]+tem.score[3])/3;
        ans.push_back(tem);
    }
    //sort
    int ti=0,pos;

    for(;flag<4;++flag)                  //important...
    {
        sort(ans.begin(),ans.end(),cmp);
        for(int j=0;j<ans.size();++j)
        {
            if(ans[j].score[flag]!=ti)           //这边可以回去看看优化
            {
                ans[j].rank[flag]=j+1;
                pos=j+1;
            }
            else
            {
                ans[j].rank[flag]=pos;
            }
            ti=ans[j].score[flag];
        }
    }
        
    for(int i=0;i<ans.size();++i)
    {
        dit[ans[i].id]=i;
    }

    string str;

    for(int i=0;i<num_ver;++i)
    {
        cin>>str;
        if(dit.find(str)!=dit.end())
            cout<<*min_element(ans[dit[str]].rank,ans[dit[str]].rank+4)<<" "<<as[(min_element(ans[dit[str]].rank,ans[dit[str]].rank+4)-ans[dit[str]].rank)]<<endl;    
        else
        {
            cout<<"N/A"<<endl;
        }
    }
    return 0;
}







