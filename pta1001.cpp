
#include <bits/stdc++.h>                      //导入万能库
#define MAX 501                             //set  the maxsize
#define INF 0x7fffffff                      //set  the edge of INF
using namespace std;

 
int main(void)
{
    string a,b,sum;
    int tem;
    cin >> a>>b;  
    tem=stoi(a)+stoi(b);
    ostringstream temp; 
    temp << abs(tem);           
    sum=temp.str();
    int len=sum.length();
   
    while(len>3)
    {
        sum.insert(len-3,",");
        len-=3;
    }
    if(tem<0)
    sum="-"+sum;
    cout<<sum;
                                   
    return 0;
}


