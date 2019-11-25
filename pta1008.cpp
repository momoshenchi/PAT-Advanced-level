
#include <bits/stdc++.h>                      
#define MAX 501                            
#define INF 0x7fffffff    
using namespace std;


int main(void)
{
    
    int now=0,n;
    int sum=0,tem;

    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>tem;
        if(tem>now)
            sum+=6*(tem-now);
        else
        {
            sum+=4*(now-tem);
        }
        now=tem;
        sum+=5;
    }
  
    cout<<sum;
    return 0;
}

