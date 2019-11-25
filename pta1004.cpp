
#include <bits/stdc++.h>                      //导入万能库
#define MAX 501                             //set  the maxsize
#define INF 0x7fffffff                      //set  the edge of INF
using namespace std;
struct node{
    vector<int>child;
};
node dit[101];
 
int main(void)
{

    int tem,n,n_non,my_id;
    int  chi_id;

    cin >> n>>n_non;  
    for(int i=0;i<n_non;++i)
    {
        cin>>my_id>>tem;
        for(int j=0;j<tem;++j)
        {
            cin>>chi_id;
            dit[my_id].child.push_back(chi_id);
        }
    }

    deque<int>deq;
    vector<int>cnt;
    int count;
    deq.push_back(01);                                //题目是按层分析的，这里使用层序遍历
    while(!deq.empty())                        
    {
        int len=deq.size();
        count=0;
        while(len)
        {
            tem=deq.front();
            if(dit[tem].child.size()==0)
            count++;
            deq.pop_front();
            for(int i=0;i<dit[tem].child.size();++i)
            {
                deq.push_back(dit[tem].child[i]);
            }
            len--;
        }
        cnt.push_back(count);
    }

    for(int i=0;i<cnt.size();++i)
    {
        if(i!=0)
        cout<<" ";
        cout<<cnt[i];
    }
    return 0;
}


