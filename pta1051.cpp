#include <bits/stdc++.h>
using namespace std;


int main()
{
    int max_stack,num,times,tem;
    cin>>max_stack>>num>>times;
    vector<int>sta,ans;
    for(int j=0;j<times;++j)
    {
        int sign=0,k=1;
        sta.clear();
        ans.clear();
        for(int i=1;i<=num;++i)
        {
            cin>>tem;
            ans.push_back(tem);
        }
        for(int i=0;i<num;++i)
        {
            if(sta.empty())
                sta.push_back(k++);
            if(ans[i]<sta.back())
            { 
                sign=1;
                break;
            }
            while( sta.back()!=ans[i])
                sta.push_back(k++);
            if(sta.size()>max_stack)
            {
                sign=1;
                break;
            }
            sta.pop_back();  
        }
        if(!sign)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
	return 0;
}

