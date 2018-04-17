class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int firstK=getFirstK(data,0,data.size()-1,k);
        if(firstK==-1){
            return 0;
        }
        int lastK=getLastK(data,firstK,data.size()-1,k);
        return lastK-firstK+1;
    }
    int getFirstK(vector<int>&data,int start,int last,int k){
        int res=-1;
        while(start<=last){
            int mid=start+(last-start)/2;
			///注意判断的方向
            if(data[mid]>=k){
                res=mid;
                last=mid-1;
            }else{
                start=mid+1;
            }
        }
        return res==-1 ? res : (data[res]==k ? res : -1);
    }
    int getLastK(vector<int>&data,int start,int last,int k){
        int res=-1;
        while(start<=last){
            int mid=start+(last-start)/2;
            if(data[mid]<=k){
                res=mid;
                start=mid+1;
            }else{
                last=mid-1;
            }
        }
        return res==-1 ? res : (data[res]==k ? res : -1);
    }
};