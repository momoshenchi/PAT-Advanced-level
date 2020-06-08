
#include <bits/stdc++.h>                      //导入万能库
using namespace std;
#define MAX 1001
#define INF 0x7fffffff
int n,v;

void ge_do(vector<vector<int>> G,int num);
void dfs(int v,vector<vector<int>> G,bool vis[]);


int main(void)
{
    int num_g;int a,b;
    cin>>n>>v>>num_g;
    vector<vector<int>> G(n+2,vector<int>(n+2,INF));
    for(int i=0;i<v;++i)
    {
        cin>>a>>b;
        G[a][b]=1;
        G[b][a]=1;
    }

    for(int i=0;i<num_g;++i)
    {
        cin>>a;
        ge_do(G,a);
    }
    return 0;
}


void ge_do(vector<vector<int>> G,int num)
{
    bool vis[n+5]={0};
    vis[num]=1;
    int cnt=0;
    for(int i=1;i<=n;++i)
    {
        if(!vis[i])
        {
            dfs(i,G,vis);
            cnt++;
        }
    }
    cout<<cnt-1<<endl;
}


void dfs(int v,vector<vector<int>> G,bool vis[])
{
   
    vis[v]=1;
    for(int i=1;i<=n;++i)
    {
        if(G[v][i]!=INF&&vis[i]==0)
        {
            dfs(i,G,vis);
        }
    }

}


/*
3 2 1
1 2
1 3
2

*/