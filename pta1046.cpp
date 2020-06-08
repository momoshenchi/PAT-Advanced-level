#include <bits/stdc++.h>
using namespace std;
int n;
void pos(int a,int b);
vector<int>dp;

int main()
{
    int tem,a,b,pai,num;cin>>n;
    dp.resize(n+5);
    dp[1]=0;
    for(int i=1;i<=n;++i)
    {
        cin>>tem;
        dp[i+1]=dp[i]+tem;
    }
    cin>>pai;
    for(int i=0;i<pai;++i)
    {
        cin>>a>>b;
        pos(a,b);
    }
	return 0;
}

void pos(int a,int b)
{
    int L=min(a,b);
    int R=max(a,b);
    int sum=dp[R]-dp[L];
    sum=min(sum,dp[n+1]-sum);
    cout<<sum<<endl;
}