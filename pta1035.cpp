#include <bits/stdc++.h>
using namespace std;
const int radix = 13;
struct node{
    string name;
    string psd;
};
vector<node>ans;
int mo_psd(node &tem);

int main()
{
    string str;int n,cnt=0;
    cin>>n;node tem;
  
    for(int i=0;i<n;++i)
    {
        cin>>tem.name>>tem.psd;
        if(mo_psd(tem))
        {
            ans.push_back(tem);
        }
    }
    //tihuan
    cnt=ans.size();
    if(cnt==0 &&n>1)
    {
        cout<<"There are "<<n<<" accounts and no account is modified"<<endl;
        return 0;
    }
    else if(cnt==0 &&n==1)
    {
        cout<<"There is 1 account and no account is modified"<<endl;
        return 0;
    }
    cout<<cnt<<endl;
    for(node i:ans)
    {
        cout<<i.name<<" "<<i.psd<<endl;
    }
	return 0;
}



int mo_psd(node &tem)
{
    string s=tem.psd;
    int sign=0;
    for(int i=0;i<tem.psd.length();++i)
    {
        if(s[i]=='l')
        {
            sign=1;
            tem.psd[i]='L';
        }
        else if(s[i]=='1')
        {
            sign=1;
            tem.psd[i]='@';
        }
        else if(s[i]=='0')
        {
            sign=1;
            tem.psd[i]='%';
        }
        else if(s[i]=='O')
        {
            sign=1;
            tem.psd[i]='o';
        }
    }
    if(!sign)
        return 0;
    return 1;
}