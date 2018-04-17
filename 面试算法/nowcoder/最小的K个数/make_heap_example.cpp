#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<int>nums={9,5,2,4,0,1,8,3,6};
    vector<int>nums2={9,5,2,4,0,1,8,3,6};
	///从大到小排序
    sort(nums2.begin(),nums2.end(),greater<int>());
    for(int i=0;i<nums2.size();i++){
        cout<<nums2[i]<<"  ";
    }
    cout<<endl;


    ///建立最大堆
    make_heap(nums.begin(),nums.end());
    make_heap(nums.begin(),nums.end() ,less<int>());
    cout<<"最大堆:";
    while(!nums.empty()){
        cout<<nums[0]<<"  ";
        ///如果先用vector的pop_back()，它删除的不是堆顶元素（nums[0]），而是vector的最后一个元素。
        ///pop_heap()把堆顶元素放到了最后一位，然后对它前面的数字重建了堆。
        ///这样一来只要再使用pop_back()把最后一位元素删除，就得到了新的堆。
        pop_heap(nums.begin(),nums.end(),less<int>() );
        nums.pop_back();
    }
    cout<<endl;
    for(int i=0;i<nums2.size();i++){
        /**
        * 建堆步骤
        */
        nums.push_back(nums2[i]);
        push_heap(nums2.begin(),nums2.end(),less<int>());
    }
    ///建立最小堆
    make_heap(nums.begin(),nums.end(),greater<int>());
    cout<<"最小堆:";
    while(!nums.empty()){
        cout<<nums[0]<<"  ";
        pop_heap(nums.begin(),nums.end(),greater<int>() );
        nums.pop_back();
    }
    cout<<endl;
    return 0;
}
