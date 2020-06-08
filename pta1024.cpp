#include <bits/stdc++.h>
using namespace std;
bool var_palin(string str);
string s_reverse(string str);
string pro(string a,string b);
int main()
{
	map<char,int>dit;
	int n,max_re;
    string sum;cin>>sum>>max_re;

    for(int i=0;i<max_re;++i)
    {
        if(!var_palin(sum))
        {
            cout<<sum<<endl;
            cout<<i;
            return 0;
        }
        sum=pro(sum,(s_reverse(sum)));
    }
 
    cout<<sum<<endl;
    cout<<max_re;
	return 0;
}

bool var_palin(string str)
{
    for(int i=0;i<str.size()/2;++i)
    {
        if(str[i]!=str[str.size()-i-1])
        {
            return 1;
        }
    }
    return 0;
}

string s_reverse(string str)
{
    
    reverse(str.begin(),str.end());
    return  str;
}

string pro(string a,string b)
{
    string sum="";
    
    while(a.size()<b.size())
    {
        a.insert(0,"0");
    }
    while(a.size()>b.size())
    {
        b.insert(0,"0");
    }
    int len=min(a.size(),b.size());
    int carry=0;
    for(int i=len-1;i>=0;--i)
    {
        ostringstream temp;
        temp<<(a[i]-'0'+b[i]-'0'+carry)%10;
        sum=temp.str()+sum;
        carry=(a[i]-'0'+b[i]-'0'+carry)/10;
    }
    
    if(carry==1)
    {
        sum="1"+sum;
    }
    return sum;
}