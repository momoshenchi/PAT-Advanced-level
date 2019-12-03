
#include <bits/stdc++.h>                      //导入万能库
#define MAX 501                             //set  the maxsize
#define INF 0x7fffffff                      //set  the edge of INF
using namespace std;

bool jug_prime(int n);
string to_num(int num,int radix);
int to_s(string num,int radix);

int main(void)
{
    int radix,num;

    while(1)
    {
        cin>>num;
        if(num<0)
            break;
        else
        {
            cin>>radix;
        }
        if(jug_prime(num))
            cout<<"No"<<endl;
        else
        {
            string to_pri=to_num(num,radix);
            reverse(to_pri.begin(),to_pri.end());
            int as=to_s(to_pri,radix);
            if(jug_prime(as))
                cout<<"No"<<endl;
            else
            {
                cout<<"Yes"<<endl;
            }
        }
        
    }
    
    return 0;
}

bool jug_prime(int n)
{
    if(n==1)
        return 1;
    for(int i=2;i<=(int)sqrt(n);++i)
    {
        if(n%i==0)
            return 1;
    }
    return 0;
}

string to_num(int num,int radix)            十进制转radix
{
    stack<int>sta;
    while(num)
    {
        sta.push(num%radix);
        num/=radix;
    }
    string s="";
    while(!sta.empty())
    {
        s.push_back(sta.top()+'0');
        sta.pop();
    }
    return s;
}

int to_s(string num,int radix)             //转为十进制
{
    int sum=0;
    for(int i=0;i<num.size();++i)
    {
        sum=sum*radix+num[i]-'0';
    }
    return sum;
}