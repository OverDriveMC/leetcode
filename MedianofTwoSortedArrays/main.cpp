#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1=nums1.size();
        int len2=nums2.size();
        int len=len1+len2;
        if(len&1){
            ///假如为奇数，直接找第(len/2+1)大的数
            return findMedian(nums1,0,len1,nums2,0,len2,len/2+1);
        }else{
            ///为偶数分别找第(len/2)与(len/2+1)大的数
            double mid1=findMedian(nums1,0,len1,nums2,0,len2,len/2);
            double mid2=findMedian(nums1,0,len1,nums2,0,len2,len/2+1);
            return (mid1+mid2)/2;
        }
    }
    double findMedian(vector<int>& nums1, int start1,int len1,
                       vector<int>& nums2,int start2,int len2,
                       int k){
        ///保证len1始终小于len2，即前面的数组永远是短的那个
        if(len2<len1){
            return findMedian(nums2,start2,len2,nums1,start1,len1,k);
        }
/*
        cout<<".................................."<<endl;
        cout<<"k:"<<k<<endl;
        cout<<"start1:"<<start1<<"    len1:"<<len1<<endl;
        for(int i=start1;i<start1+len1;i++){
            cout<<nums1[i]<<"   ";
        }
        cout<<endl;
        cout<<"start2:"<<start2<<"    len2:"<<len2<<endl;
        for(int i=start2;i<start2+len2;i++){
            cout<<nums2[i]<<"   ";
        }
        cout<<endl;
        cout<<".................................."<<endl;
*/
        ///假如前面的长度为0，即在后面的数组中找到第k大即可
        if(len1==0){
            return nums2[start2+k-1];
        }
        ///假如k=1，则为找第一大的数，直接两边取小的即可
        ///当len1!=0且中位数不是两边公有的情况即为这种情况
        if(k==1){
            return min(nums1[start1],nums2[start2]);
        }

        int pa=min(k/2,len1);
        int pb=k-pa;
        ///保证pa+pb=k
        if(nums1[start1+pa-1]<nums2[start2+pb-1]){
            return findMedian(nums1,start1+pa,len1-pa,nums2,start2,len2,k-pa);
        }else if(nums1[start1+pa-1]>nums2[start2+pb-1]){
            return findMedian(nums1,start1,len1,nums2,start2+pb,len2-pb,k-pb);
        }else{
            return nums1[start1+pa-1];
        }
    }
};


int main(){
    int a[]={1,3};
    vector<int>nums1=vector<int>(a,a+2);
    int b[]={2,4};
    vector<int>nums2=vector<int>(b,b+2);
    Solution s;
    cout<<s.findMedianSortedArrays(nums1,nums2)<<endl;

    cout<<"-------------------------------------"<<endl;
    int c[]={1,2,3};
    nums1=vector<int>(c,c+3);
    int d[]={2,4};
    nums2=vector<int>(d,d+2);
    cout<<s.findMedianSortedArrays(nums1,nums2)<<endl;
    return 0;
}
