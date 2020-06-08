

#include <bits/stdc++.h>                      //导入万能库
#define MAX 101                             
#define INF 0x7fffffff                     
using namespace std;

int main(void)
{
    
    int carry=0;
    int a[3],b[3];
    int sum[3];
    scanf("%d.%d.%d",&a[0],&a[1],&a[2]);
    scanf("%d.%d.%d",&b[0],&b[1],&b[2]);
    sum[2]=(a[2]+b[2]+carry)%29;
    carry=(a[2]+b[2]+carry)/29;
    sum[1]=(a[1]+b[1]+carry)%17;
    carry=(a[1]+b[1]+carry)/17;
    sum[0]=(a[0]+b[0]+carry);
    printf("%d.%d.%d",sum[0],sum[1],sum[2]);
    return 0;
}

