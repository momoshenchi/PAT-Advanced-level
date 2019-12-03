#include <bits/stdc++.h>
using namespace std;
const int radix = 13;
char rax[15];
string to_num(int num);


int main()
{
	int a[3];
    for(int i=0;i<10;++i)
    {
        rax[i]=i+'0';
    }
    rax[10]='A';rax[11]='B';rax[12]='C';

	int n,radix;cin>>a[0]>>a[1]>>a[2];
    string ss;
    cout<<"#";
    for(int i=0;i<3;++i)
    {
        ss=to_num(a[i]);
        cout<<ss;
    }
    cout<<endl;
	
	return 0;
}


string to_num(int num){     //十进制转radix
           
    stack<int>sta;string s;
    if(num==0)
        s+='0';
    while(num)
    {
        sta.push(num%radix);                    //exist problem
        num/=radix;
    }
    
    while(!sta.empty())
    {
        s.push_back(rax[sta.top()]);
        sta.pop();
    }
    if(s.size()<2)
        s='0'+s;
    return s;
}

