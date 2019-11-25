
#include <bits/stdc++.h>                      
#define MAX 501                            
#define INF 0x7fffffff    
using namespace std;
int nv;
int vertex[MAX];
int G[MAX][MAX];
int low[MAX];
bool vis[MAX];
int num[MAX];         //不同路径数量
int v_w[MAX];
void dijk(int fir);



int main(void)
{
    
    int tem,n1,n2,wei;
    int ne,first,last;
    
    cin>>nv>>ne>>first>>last;
    fill(G[0],G[0]+MAX*MAX,INF);
    for(int i=0;i<nv;++i)
    {
       cin>>vertex[i];
    }
    for(int i=0;i<ne;++i)
    {
        cin>>n1>>n2>>wei;
        G[n1][n2]=wei;
        G[n2][n1]=wei;
    }

    dijk(first);
    cout<<num[last]<<" "<<v_w[last];
            
    return 0;
}


void dijk(int fir)
{
    fill(low,low+MAX,INF);
  //  fill(v_w,v_w+MAX,INF);
    low[fir]=0;
    num[fir]=1;
    v_w[fir]=vertex[fir];
    for(int i=0;i<nv;++i)
    {
        int minid=-1;
        int min_s=INF;
        for(int j=0;j<nv;++j)
        {
            if(!vis[j]&&low[j]<min_s)
            {
                minid=j;
                min_s=low[j];
            }
        }
        vis[minid]=true;
        for(int j=0;j<nv;++j)
        {
            if(!vis[j]&&G[minid][j]!=INF)
            {
                if(low[minid]+G[minid][j]<low[j])
                {  
                    low[j]=low[minid]+G[minid][j];
                    v_w[j]=v_w[minid]+vertex[j];
                    num[j]=num[minid];       
                }
                else if(low[minid]+G[minid][j]==low[j])
                {
                    if(v_w[j]<v_w[minid]+vertex[j])
                        v_w[j]=v_w[minid]+vertex[j];
                    num[j]+=num[minid];
                }         
            }
        }
    }
}