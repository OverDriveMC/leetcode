/**
default (1) template <class ForwardIterator, class T> ForwardIterator upper_bound (ForwardIterator first, ForwardIterator last, const T& val)
							指向[first , last)中第一个>val的元素；
custom (2) template <class ForwardIterator, class T, class Compare> ForwardIterator upper_bound (ForwardIterator first, ForwardIterator last, const T& val, Compare comp);
							指向[first , last)中第一个>val的元素，自定义<运算符；
default (1) template <class ForwardIterator, class T> ForwardIterator lower_bound(ForwardIterator first, ForwardIterator last, const T& val);
							指向[first , last)中第一个>=val的元素
custom (2) template <class ForwardIterator, class T, class Compare> ForwardIterator lower_bound(ForwardIterator first, ForwardIterator last, const T& val, Compare comp);
							指向[first , last)中第一个>=val的元素，自定义<运算符
以上两种boun在使用时，需要保证[begin , end)中元素已经有序。
*/


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
		///维护长度为i的最长上升序列的最后一个数
        vector<int>res;
        for(int i=0;i<nums.size();i++){
			///假如为空直接进入集合
            if(res.empty() ){
                res.push_back(nums[i]);
            }else if(res[0]>nums[i] ){
				///假如小于最小的,那么直接放在0的位置
                res[0]=nums[i];
            }else if(res[res.size()-1] <nums[i]){
				///大于最大的数,说明最长上升子序列可以+1,直接丢在最后面
                res.push_back(nums[i]);
            }else{
				///找到该字符在最长子序列中的位置,替换成更小的数(假如原来长度为2的最后一个数是10,当前的数为5,如果之后有个6,就可以和5一起形成一个
				///更长的上升子序列,所以需要用5替下来10)
                vector<int>::iterator index=lower_bound(res.begin(),res.end(),nums[i]);
                if(*index !=nums[i]){
                    *index=nums[i];
                }
            }
        }
        return res.size();
    }
};