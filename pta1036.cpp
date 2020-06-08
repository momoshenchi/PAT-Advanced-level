#include <bits/stdc++.h>
using namespace std;
const int radix = 13;
struct node{
    string name;
    string id;
    int score;
    char gender;
   
};
vector<node>ans;

void pri(node tem,char s);
bool cmp(node a,node b)
{
    if(a.gender!=b.gender)
        return a.gender<b.gender;
    return a.score>b.score;
}
int main()
{
    string str;int n,cnt=0;
    cin>>n;node tem;
  
    for(int i=0;i<n;++i)
    {
        cin>>tem.name>>tem.gender>>tem.id>>tem.score;
        ans.push_back(tem);
    }
    //tihuan
    int sign1=0,sign2=0;
    sort(ans.begin(),ans.end(),cmp);
    pri(ans[0],'F');
    pri(ans.back(),'M');
    
    if(ans[0].gender=='F'&&ans.back().gender=='M')
        cout<<ans[0].score-ans.back().score;
    else
    {
        cout<<"NA"<<endl;
    }
    
	return 0;
}


void pri(node tem,char s)
{
    if(tem.gender==s)
    {
        cout<<tem.name<<" "<<tem.id<<endl;
        return ;
    } 
    cout<<"Absent"<<endl;
    return ;

}