#include <bits/stdc++.h>
using namespace std;
const int radix = 13;

vector<int>s1;
vector<int>s2;

int  findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
int main()
{
    int tem,n;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>tem;
        s1.push_back(tem);
    }
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>tem;
        s2.push_back(tem);
    }
	cout<<findMedianSortedArrays(s1,s2);
	return 0;
}


int findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size())
            return findMedianSortedArrays(nums2,nums1);
        int len1=nums1.size(),len2=nums2.size();
        int L=0,R=len1;int i,j;
        int max1,max2;
        while(L<=R)
        {
            int i=L+((R-L)>>1);
            int j=(len1+len2+1)/2-i;
            if(i>L &&nums1[i-1]>nums2[j])
                R=i-1;
            else if(i<R &&nums2[j-1]>nums1[i])
                L=i+1;
            else
            {
                if(i==0)
                {
                    max1=nums2[j-1];
                }
                else if(j==0)
                    max1=nums1[i-1];
                else
                {
                    max1=max(nums2[j-1],nums1[i-1]);
                }
                if((len1+len2)%2==1)
                    return max1;

                if(i==len1)
                {
                    max2=nums2[j];
                }
                else if(j==len2)
                {
                    max2=nums1[i];
                }
                else
                    max2=min(nums2[j],nums1[i]);
                return (max1+max2)/2;
            }
        }
        return -1;
    }