class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for(int i=0;i<nums2.size();i++){
            nums1.push_back(nums2[i]);
        }
		/**
		* 做一下随机
		*/
        random_shuffle(nums1.begin(),nums1.end());
        quickSort(nums1,0,nums1.size()-1);
        
        if(nums1.size()&1){
            return nums1[nums1.size()/2 ];
        }else{
            int mid=nums1.size()/2;
            return (nums1[ mid] + nums1[mid-1] )/2.0;
        }
    }
    void quickSort(vector<int>&nums,int start,int end){
        if(start<end){
            int pos=start;
            int privot=nums[start];
            for(int i=start+1;i<=end;i++){
                if(nums[i]<privot){
                    swap(nums[i],nums[++pos]);
                }
            }
            swap(nums[start],nums[pos]);
            
            quickSort(nums,start,pos-1);
            quickSort(nums,pos+1,end);
        }
    }
};