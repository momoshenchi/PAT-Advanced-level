
#include <bits/stdc++.h>                      //导入万能库
#define MAX 501                             //set  the maxsize
#define INF 0x7fffffff                      //set  the edge of INF
using namespace std;


long long int n_find(long long int n,string num);
long long int g_num(long long int radix,string num);


int main(void)
{
    
    string n1,n2;
    long long int radix,sign=0;
    int tags;
  
    cin>>n1>>n2>>tags>>radix;
    if(tags==1)
    {
        sign=n_find(g_num(radix,n1),n2);
    }
    else if(tags==2)
    {
        sign=n_find(g_num(radix,n2),n1); 
    }


    if(!sign)
    {
        cout<<"Impossible";
    }
    else
    {
        cout<<sign;
    }
    return 0;
}


long long int g_num(long long int radix,string num)
{
    long long int sum=0;
    for(int i=0;i<num.length();++i)
    {
        if(num[i]>='0'&&num[i]<='9')
        {
            sum=sum*radix+(num[i]-'0');   
        }
        else 
        {
            sum=sum*radix+(num[i]-'a'+10); 
        }
    }
    return sum;
}

long long int n_find(long long int n,string num)
{
    long long int L;
    char s=*max_element(num.begin(),num.end());
    if(s>='0' &&s<='9')
       L=s-'0'+1;
    else
    {
        L=s-'a'+10+1;
    }
    
    long long int R=max(n,L);
    while(L<=R)
    {
        long long int mid=L+((R-L)>>1);
        long long int sum=g_num(mid,num);
        if(sum==n)
        {
            return mid;
        }
        else if(sum>n ||sum<0)
        {
            R=mid-1;
        }
        else if(sum<n)
        {
            L=mid+1;
        }
    }
    return 0;
}