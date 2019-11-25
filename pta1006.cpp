
#include <bits/stdc++.h>                      
#define MAX 501                            
#define INF 0x7fffffff    
using namespace std;
struct node{
    string id;
    string ear,las;
    node(string _id,string _ear,string _las):id(_id),ear(_ear),las(_las){}
};
vector<node>dit;

bool cmp1(node a,node b)
{
    return a.las<b.las;
}


bool cmp2(node a,node b)
{
    return a.ear<b.ear;
}

int main(void)
{
    int n;
    cin>>n;
    

    string a,b,c;
    for(int i=0;i<n;++i)
    {
        cin>>a>>b>>c;
        dit.push_back(node(a,b,c));
    }

    cout<<min_element(dit.begin(),dit.end(),cmp2)->id;
    cout<<" "<<max_element(dit.begin(),dit.end(),cmp1)->id; 
    return 0;
}

