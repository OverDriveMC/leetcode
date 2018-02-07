/**
可以直接考虑倒着往里加
这样便不存在覆盖的情况
*/

class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int i=m-1,j=n-1;
        int pos=m+n-1;
        while(i>=0 || j>=0){
            if(i<0 || (j>=0 && nums1[i]<nums2[j] ) ){
                nums1[pos--]=nums2[j--];
            }else{
                nums1[pos--]=nums1[i--];
            }
        }
    }
}