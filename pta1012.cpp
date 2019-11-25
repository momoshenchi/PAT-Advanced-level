
#include <bits/stdc++.h>                      //导入万能库
#define MAX 501                             //set  the maxsize
#define INF 0x7fffffff                      //set  the edge of INF
using namespace std;
struct student{
    int C;
    int M;
    int E;
    double average;
   
    student(){}
    student(string _id ,int _C ,int _M,int _E):id(_id),C(_C),M(_M),E(_E){}
};
map<string,student>ans;
void pri(string id);



int main(void)
{
    int num_stu,num_ver;
    student tem;string id;
    cin>>num_stu>>num_ver;

    for(int i=0;i<num_stu;++i)
    {
        cin>>id>>tem.C>>tem.M>>tem.E;
        tem.average=(tem.C+tem.M+tem.E)/3;
        ans[id]=tem;
    }
    string temid;
    for(int i=0;i<num_ver;++i)
    {
        cin>>temid;
        if(ans[temid])
        pri(temid);
        else
        {
            cout<<"N/A";
        }
        
    

    }
    return 0;
}

void pri(string id)
{
    
    map<char,int>dit;
    sort()

}


bool cmp(student a,student b)
{
    if(a.average>b.average)
}