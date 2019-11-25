
#include <bits/stdc++.h>                      
#define MAX 50100                        
#define INF 0x7fffffff    
using namespace std;


int main(void)
{
    
    int n; 
    cin>>n;

    int sum=-1,tem=0,tempfir=0;
    int fir=0,las=n-1;
    vector<int>a(n);
   
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        tem+=a[i];
        if(tem>sum)
        {
            sum=tem;
            las=i;
            fir=tempfir;
        }
        if(tem<0)
        {
            tempfir=i+1;
            tem=0;
        }
    }
    if(sum<0)
    sum=0;
   cout<<sum<<" "<<a[fir]<<" "<<a[las];
    return 0;
}

