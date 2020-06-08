#include <bits/stdc++.h>
using namespace std;
const int radix = 13;

vector<int>ans;
vector<int>product;
bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    string str;int n,cnt=0;
    cin>>n;int tem;
  
    for(int i=0;i<n;++i)
    {
        cin>>tem;
        ans.push_back(tem);
    }
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>tem;
        product.push_back(tem);
    }
    //tihuan
    int sign1=0,sign2=0;
    sort(ans.begin(),ans.end(),cmp);
    sort(product.begin(),product.end(),cmp);
    int sum=0,i;
    int len=min(ans.size(),product.size());
    for(i=0;i<len;++i)
    {
        if(ans[i]>0&&product[i]>0)
        {
            sum+=ans[i]*product[i];
        }
        else
        {
            break;
        }
        
    }
    for(int j=len-1;j>=i;--j)
    {
        if(ans.back()<0&&product.back()<0)
        {
            sum+=ans.back()*product.back();
            ans.pop_back();
            product.pop_back();
        }
        else
        {
            break;
        }
    }
    cout<<sum;
	return 0;
}

