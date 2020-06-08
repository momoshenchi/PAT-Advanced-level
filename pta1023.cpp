#include <bits/stdc++.h>
using namespace std;


int main()
{
	map<char,int>dit;
	int n,carry=0;
    string tem,sum="";cin>>tem;

	
    for(int i=tem.size()-1;i>=0;--i)
    {
        dit[tem[i]]++;
        ostringstream temp;
        temp<<((tem[i]-'0')*2+carry)%10;
        sum=temp.str()+sum;
        carry=((tem[i]-'0')*2+carry)/10;
    }
    if(carry==1)
    {
        sum="1"+sum;
    }
    for(int i=0;i<sum.length();++i)
    {
        if(dit[sum[i]])
            dit[sum[i]]--;
        else
        {
            cout<<"No"<<endl;
            cout<<sum;
            return 0;
        }
    }
    
	cout<<"Yes"<<endl;
    cout<<sum;
	return 0;
}

