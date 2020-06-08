#include <bits/stdc++.h>
using namespace std;


int LPS(string str)
{
    int len=1;                                     //len可以变成其他形式,可以返回最长字符串
    bool dp[str.size()][str.size()]={0};
    for(int i=0;i<str.size()-1;++i)
    {
        dp[i][i]=1;
        if(str[i]==str[i+1])
        {
            dp[i][i+1]=1;
            len=2;
        }
    }
    dp[str.size()-1][str.size()-1]=1;
    for(int k=2;k<str.size();++k)
    {
        for(int i=0;i+k<str.size();++i)
        {
            if(str[i]==str[i+k]&&dp[i+1][i+k-1])
            {
                len=k+1;
                dp[i][k+i]=1;
            }
        }
    }
    return len;
}

































int main()
{
    string str;
    getline(cin,str);
    cout<<LPS(str);
	return 0;
}