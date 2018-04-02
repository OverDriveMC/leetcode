class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for(int i=0;i<nums2.size();i++){
            nums1.push_back(nums2[i]);
        }
        random_shuffle(nums1.begin(),nums1.end());

        quickSort(nums1,0,nums1.size()-1);
        
       
        
        if(nums1.size()&1){
            return nums1[nums1.size()/2 ];
        }else{
            int mid=nums1.size()/2;
            return (nums1[ mid] + nums1[mid-1] )/2.0;
        }
    }
    int partitation(vector<int>&nums,int start,int end){
        int pos=start;
        int privot=nums[start];
        for(int i=start+1;i<=end;i++){
            if(nums[i]<privot){
                swap(nums[i],nums[++pos]);
            }
        }
        swap(nums[start],nums[pos]);
        return pos;
    }
    void quickSort(vector<int>&nums,int start,int end){
        stack<int>st;
        if(start<end){
            int mid=partitation(nums,start,end);
			/**
			* 每次把需要进行partitation的位置存到栈里面
			*然后每次取出来进行partitation操作即可
			*/
            if(start<mid-1){
                st.push(start);
                st.push(mid-1);
            }
            if(end>mid+1){
                st.push(mid+1);
                st.push(end);
            }
            while(!st.empty()){
                int q=st.top();
                st.pop();
                int p=st.top();
                st.pop();
                int mid=partitation(nums,p,q);
                if(p<mid-1){
                    st.push(p);
                    st.push(mid-1);
                }
                if(q>mid+1){
                    st.push(mid+1);
                    st.push(q);
                }
            }
        }
    }
};