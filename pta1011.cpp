
#include <bits/stdc++.h>                      //导入万能库
#define MAX 501                             //set  the maxsize
#define INF 0x7fffffff                      //set  the edge of INF
using namespace std;

double ans[4][4];

void pri (double ans[][4],int num);

int main(void)
{
    int n1,n2,n3,tem;
    double sum=0;

    for(int i=0;i<3;++i)
    {
        for(int j=1;j<=3;++j)
        {
            cin>>ans[i][j];
        }
    }

    sum+=2*(*max_element(ans[0],ans[0]+4)**max_element(ans[1],ans[1]+4)**max_element(ans[2],ans[2]+4)*0.65-1);
    pri(ans,0);
    pri(ans,1);
    pri(ans,2);
    printf("%.2f",sum);
    return 0;
}

void pri (double ans[][4],int num)
{
    if((max_element(ans[num],ans[num]+4)-ans[num])==1)
    {
        cout<<"W"<<" ";
    }
    else if ((max_element(ans[num],ans[num]+4)-ans[num])==2)
    {
        cout<<"T"<<" ";
    }
    else if ((max_element(ans[num],ans[num]+4)-ans[num])==3)
    {
        cout<<"L"<<" ";
    }
}