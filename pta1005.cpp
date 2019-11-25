
#include <bits/stdc++.h>                      
#define MAX 501                            
#define INF 0x7fffffff    
using namespace std;

string number[11]={"zero","one","two","three","four","five","six","seven","eight","nine"};

int main(void)
{
    
    string str,tem;
    int sum=0;
    cin>>str;
    
    for(int i=0;i<str.length();++i)
    {
       sum+=str[i]-'0';
    }
    ostringstream temp; 
    temp << sum;          
    tem=temp.str();
    for(int i=0;i<tem.length();++i)
    {
        if(i!=0)
        cout<<" ";
        cout<<number[tem[i]-'0'];
    }
    return 0;
}

