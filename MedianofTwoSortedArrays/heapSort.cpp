class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for(int i=0;i<nums2.size();i++){
            nums1.push_back(nums2[i]);
        }
        heapSort(nums1);
        /*
        for(int num : nums1){
            cout<<num<<"  ";
        }
        cout<<endl;
        */
        if(nums1.size()&1){
            return nums1[nums1.size()/2 ];
        }else{
            int mid=nums1.size()/2;
            return (nums1[ mid] + nums1[mid-1] )/2.0;
        }
    }
    void heapSort(vector<int>&nums){
		//先建立一个大根堆,从最后一个有叶子结点的位置开始调整
		///每次将以该位置为根的堆调整为大根堆
        for(int i=nums.size()/2-1; i>=0;i--){
            adjustHeap(i,nums,nums.size());
        }
        int len=nums.size();
        while(len--){
			///每次将根(最大的元素)移到最后,然后重新维护一个长度为len-1的大根堆
			///因为是把最后一个元素移到第一位,所以只要重新调节下即可
            swap(nums[0],nums[len]);
            adjustHeap(0,nums,len);
        }
    }
    void adjustHeap(int pos,vector<int>&nums, int len){
        while(pos<len){
            int left=pos*2+1;
			/**
			* 使用左右节点大的元素与根节点交换
			*/
            int next=pos;
            if(left<len && nums[pos]<nums[left]){
                next=left;
            }
            int right=left+1;
            if(right<len && nums[next]<nums[right]){
                next=right;
            }
			///假如不能交换,说明已经符合堆的性质
            if(pos==next){
                break;
            }
            swap(nums[pos],nums[next]);
            pos=next;
        }
    }
};