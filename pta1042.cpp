#include <bits/stdc++.h>
using namespace std;

map<int,int>dit;
vector<string>card(55);
vector<int>ans(55);
char color[]={0,'S','H','C','D','J'};
void suffle();
int main()
{
    
    int n,tem;cin>>n;
    for(int k=1;k<=4;++k)
    {
        for(int i=1;i<=13;++i)
        {
        ostringstream temp;
        temp<<i;
        card[i+(k-1)*13]=color[k]+temp.str();
        }
    }
    card[53]="J1";card[54]="J2";

    for(int i=1;i<=54;++i)
    {
        cin>>ans[i];
    }

    for(int i=0;i<n;++i)
    {
        suffle();
    }
    for(int i=1;i<=54;++i)
    {
        if(i!=1)
        cout<<" ";
        cout<<card[i];
    }
   
	return 0;
}



void suffle()
{
    vector<string>tem(55);
    for(int i=1;i<=54;++i)
    {
        tem[ans[i]]=card[i];
    }
    for(int i=1;i<=54;++i)
    {
        card[i]=tem[i];
    }

}