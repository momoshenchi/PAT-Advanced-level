

#include <bits/stdc++.h>                      //导入万能库
#define MAX 501010                             
#define INF 0x7fffffff                     
using namespace std;
void pri(string s1,string s2);
int max_n;
int a1,a2;int count1=0,count2=0;
int main(void)
{
    
    
    string s1,s2;
    long long int sum;
    
    cin>>max_n>>s1>>s2;
    a1=stof(s1);a2=stof(s2);
    
    while(a1)
    {
        count1++;
        a1/=10;
    }
    while (a2)
    {
        count2++;
        a2/=10;
    }
    for(int i=0;i<max_n;++i)
    {
        if(i>=s2.size()||i>=s1.size())
            break;
        if(s1[i]!=s2[i])
        {
            cout<<"NO ";
            pri(s1,s2);
            return 0;
        }
    }
    cout<<"YES ";
    printf("0.");
    if(s1.size()>max_n)
    {
        cout<<s1.substr(0,max_n);
    }
    else
    {
        cout<<s1;
    }
    cout<<"*";
    cout<<"10^"<<count2;
    return 0;
}
void pri(string s1,string s2)
{
    printf("0.");
    if(s1.size()>max_n)
    {
        cout<<s1.substr(0,max_n);
    }
    else
    {
        cout<<s1;
    }
    cout<<"*";
    cout<<"10^"<<count1<<" ";
    printf("0.");
    if(s2.size()>max_n)
    {
        cout<<s2.substr(0,max_n);
    }
    else
    {
        cout<<s2;
    }
    cout<<"*";
    cout<<"10^"<<count2;

}