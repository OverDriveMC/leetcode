class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.size()==0){
            return 0;
        }
        int lo=0,hi=rotateArray.size()-1;
        int minn=0x7fffffff;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
			/**
			假如左边的小于中间的
			*/
            if(rotateArray[lo]<=rotateArray[mid]){
				/**
				并且中间的小于右边的,说明是有序的,所以当前最小值为rotateArray[lo]
				全局最小值为两者更小的那个
				3  1  2
				第二次循环的时候lo==high==mid  这时候是3,所以需要和之前的比较一下取最小值
				*/
                if(rotateArray[mid]<=rotateArray[hi]){
                    return min(minn,rotateArray[lo]);
                }else{
					/**
					* 说明最小取值在 mid  -----  hi 之间
					*  因为    arr[mid] >= arr[lo]    arr[mid]>=arr[hi]
					*  因为是旋转数组,arr[lo] >= arr[hi]
					*  所以当前最小为arr[hi]
					*/
                    minn=min(minn,rotateArray[hi]);
                    lo=mid+1;
                }
            }else{
				/**
				*  这种说明最小值在  lo ------------mid之间
				*/
                minn=min(minn,rotateArray[mid]);
                hi=mid-1;
            }
        }
        return minn;
    }
};