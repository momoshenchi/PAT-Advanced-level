#include <bits/stdc++.h>
using namespace std;

vector<int>pre;
vector<string> to_num(int num,int radix);
int d_palin(vector<string> str);

int main()
{
	
	int n,radix;cin>>n>>radix;
    vector<string>ss;

	ss=to_num(n,radix);

    if(d_palin(ss))
    cout<<"No"<<endl;
    else
    {
        cout<<"Yes"<<endl;
    }
    for(int i=0;i<ss.size();++i)
    {
        if(i!=0)
        cout<<" ";
        cout<<ss[i];
    }
	
	return 0;
}


vector<string> to_num(int num,int radix){     //十进制转radix
           
    stack<int>sta;
    while(num)
    {
        sta.push(num%radix);                    //exist problem
        num/=radix;
    }
    vector<string> s;
    while(!sta.empty())
    {
        ostringstream temp;
        temp << sta.top();
        s.push_back(temp.str());
        sta.pop();
    }
    return s;
}

int d_palin(vector<string> str)
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