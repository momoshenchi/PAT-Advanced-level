#include <bits/stdc++.h>
using namespace std;
int lis[]={0,1,20,300,4000,50000,600000,7000000,80000000,900000000};

int main()
{
    string str;
    cin>>str;int sum=0;
    if(str[str.length()-1]-'0'>=1)
        sum++;
    for(int i=0;i<str.length()-1;++i)
    {
        int pos=str.length()-i-1;
        sum+=lis[pos]*(str[i]-'0');

        if(str[i]-'0'>1)
            sum+=pow(10,pos);                                          //大于1,才加pow
        else if((str[i]-'0')==1)                                 //取决于1后面的数字
            sum+=stoi(str.substr(i+1,str.size()-i-1))+1;
    }
   
    cout<<sum;

	return 0;
}

