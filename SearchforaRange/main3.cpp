class Solution {
public:
    int searchLeft(vector<int>&arr,int target){
        int start=0,last=arr.size()-1,ans=-1;
        while(start<=last){
            int mid=start+(last-start)/2;
            if(arr[mid]>=target){
                ans=mid;
                last=mid-1;
            }else{
                start=mid+1;
            }
        }
		//注意为[]的情况
		///不一定arr里面一定包含target
		///因为每次arr[mid]>=target的时候都会修改ans,ans会更靠近target插入的位置
        if(ans>=0 && ans<arr.size() && arr[ans]!=target){
            ans=-1;
        }
        return ans;
    }
    int searchRight(vector<int>&arr,int target){
        int start=0,last=arr.size()-1,ans=-1;
        while(start<=last){
            int mid=start+(last-start)/2;
            if(arr[mid]<=target){
                ans=mid;
                start=mid+1;
            }else{
                last=mid-1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>res;
        int left=searchLeft(nums,target);
        res.push_back(left);
        if(left==-1){
            res.push_back(left);
        }else{
            int right=searchRight(nums,target);
            res.push_back(right);
        }
        return res;
    }
};