#include <bits/stdc++.h>
using namespace std;
const int radix = 13;

vector<int>s1;
vector<int>s2;


int main()
{
    string str;int n1,n2;
    cin>>str;
    int n=str.length();
    if(n<=4)
    {
        cout<<str<<endl;
        return 0;
    }
    n1=(n+2)/3;
    n2=n+2-2*n1;
    for(int i=0;i<n1-1;++i)
    {
        cout<<str[i];
        for(int j=0;j<n2-2;++j)
        {
            cout<<" ";
        }
        cout<<str[n-1-i]<<endl;
    }
    n1-=1;
    for(int j=0;j<n2;++j)
    {
        cout<<str[n1++];
    }
    cout<<endl;
   
	return 0;
}

