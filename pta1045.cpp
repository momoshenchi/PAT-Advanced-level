#include <bits/stdc++.h>
using namespace std;

vector<int>ans;


int main()
{
    int n,tem,like_co,num;cin>>n;
    cin>>like_co;
    vector<int>like(n+1);
    for(int i=1;i<=like_co;++i)
    {
        cin>>tem;
        like[tem]=i;
    }
    cin>>num;
    for(int i=0;i<num;++i)
    {
        cin>>tem;
        ans.push_back(tem);
    }


    int dp[num+5]={0};                            // 以i结尾的最大长度
 
                                            //如果标号不在喜欢里面,跳过,有点像那个递增序列了..
                                            //如果i-1标号在i前面,dp[i]=dp[i-1]+1;
    int max_p=0;                           
    for(int i=0;i<num;++i)
    {
        if(like[ans[i]])
        {    
            dp[i]=1;
            for(int j=i-1;j>=0;--j)                          
            {
                if(like[ans[j]]&&like[ans[i]]>=like[ans[j]])         //这就是把那个递增序列换成了dit序递增
                    dp[i]=max(dp[j]+1,dp[i]);                        //多了一步是否在字典里的判断.
            }
        }
        max_p=max(max_p,dp[i]);
    }
    cout<<max_p;                                                 //所以1个字符可能为1,可能为0
	return 0;
}

