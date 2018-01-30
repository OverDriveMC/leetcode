#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int mySqrt(int x) {
		///假如x为0,会直接退出循环,结果即为right
		int left=1,right=x;
		///这里必须要写==
		///当left>right的时候才一定能保证right是结果
		///最后一次运行的时候是left==right==mid,
		///这时候有三种情况,一种mid是结果直接返回
		///一种是mid * mid< x,然后left+1,(之前right必然是通过right-1才实现 小于right*right<x)
		///一种是mid*mid >x ,然后right-1
		while(left<=right){
			///防止越界
			int mid=left+(right-left)/2;
			///防止mid*mid越界
			if(mid== x/mid){
				return mid;
			}else if(mid<x/mid){
				///当mid<sqrt(x) left=mid+1, right指针没有移动,
				left=mid+1;
			}else{
				///当mid>sqrt(x),right=mid-1,right指针移动一位,更加接近sqrt(x)
				right=mid-1;
			}
		}

		return right;
    }
};

int main(){
    Solution s;
    for(int i=0;i<INT_MAX;i++){
        cout<<s.mySqrt(i)<<endl;
    }
    return 0;
}

/**
感觉这种更好理解
*/
class Solution {
public:
    int mySqrt(int x) {
        int left = 1, right = x, ans=x;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid <= x / mid) {
                left = mid + 1;
                ans = mid;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};