#include <bits/stdc++.h>
using namespace std;

vector<int>pre;

int main()
{
	
	int n;
	cin>>n;
	bool vis[n]={0};
	int dit[n];
	int tem,latter=n-1;
	
	for(int i = 0; i < n; i++)
	{
        cin>>tem;
        dit[tem]=i;
        if(tem==i&&tem!=0)
        {
        	latter--;
		}
		pre.push_back(tem);
	}
	int cnt=0;
	int sss,k=1;
	while(latter)
	{
		if(dit[0]==0)
		{
			for(;k<n;++k)
			{
				if(dit[k]!=k)
				{
					swap(dit[0],dit[k]);
					cnt++;
					break;
				}
			}
		}
		else
		{
			swap(dit[0],dit[dit[0]]);
			cnt++;
			latter--;
		}
			
			
	}
			
	cout<<cnt;
	
	return 0;
}

