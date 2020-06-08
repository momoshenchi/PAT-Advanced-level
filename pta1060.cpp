
#include <bits/stdc++.h>                      //导入万能库                
using namespace std;
unordered_map<string,int>dit;void pri(string s1);
int max_n;

int cnt_digit(string str)
{
    if(str.find(".")==string::npos)
    {
        return str.size();
    }
    else{
        return str.size()-1;
    }
}
double a1,a2;int cnt1=0,cnt2=0;
int main(void)
{
    
    string s1,s2;
    long long int sum;
    cin>>max_n>>s1>>s2;
    dit[s1]=cnt_digit(s1);
    dit[s2]=cnt_digit(s2);
    if(max_n>dit[s1] ||max_n>dit[s2])
    {
        max_n=min(dit[s1],dit[s2]);
    }
    string to1=s1.substr(0,max_n);
    string to2=s2.substr(0,max_n);
    dit[to1]=cnt_digit(s1);
    dit[to2]=cnt_digit(s2);
    // for(int i=0;i<max_n;++i)
    // {
    //     if(i>=s2.size()||i>=s1.size())
    //         break;
     
    //     to1+=s1[i];
    //     to2+=s2[i];
    // }
    if(to1!=to2)
    {
        cout<<"NO ";
        pri(to1);
        cout<<" ";
        pri(to2);
        return 0;
    }
    cout<<"YES ";
    pri(to1);
    return 0;
}
void pri(string s1)
{
    if(s1!="0")
    {
        printf("0.");
        cout<<s1;
        cout<<"*";
        cout<<"10^"<<dit[s1];
    }
    else
    {
        cout<<0;
    }
}