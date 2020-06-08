#include <bits/stdc++.h>
using namespace std;
char name[40010][5];
vector<int>dit[2505];
bool cmp(int a,int b)
{
    return strcmp(name[a],name[b])<0;
}
int main()
{
    int tem,num_class,num,n;
    cin>>n>>num_class;
    int num_stu;
    for(int i=0;i<n;++i)
    {
        scanf("%s %d",name[i],&num_stu);
        for(int j=0;j<num_stu;++j)
        {
            cin>>tem;
            dit[tem].push_back(i);
        }
    }
    for(int i=1;i<=num_class;++i)
    {
        printf("%d %d\n",i,dit[i].size());
        sort(dit[i].begin(),dit[i].end(),cmp);
        for(int j=0;j<dit[i].size();++j)
        {
            printf("%s\n",name[dit[i][j]]);
        }
    }

	return 0;
}

