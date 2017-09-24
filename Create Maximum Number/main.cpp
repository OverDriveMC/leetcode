#include<bits/stdc++.h>
//#define DEBUG
using namespace std;


void print(string name,vector<int>&vec){
    cout<<name<<":";
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<"  ";
    }
    cout<<endl;
}


class Solution {
public:
    /**
    * 直接贪心就可以
    *  假如当前元素比栈内的元素大,而且后续的元素数量能满足达到k个
    *  那么便一定可以加进来
    *  因为元素数量一定,高位高的数一定更大
    */
    vector<int> findMax(const vector<int>&nums,int k){
        vector<int>res(k);
        if(k==0){
            return res;
        }
        int index=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            /**
            * 不能先根据index<k 然后直接加
            * 例如 3 1 5 6       k=3
            * 假如直接加 会是 3 1 5, 加6 的时候6会替换5,因为6后面已经没有元素了
            * 所以会替换5,保证有3个
            * 所以必须要先判断后面的元素 + 当前的元素 是否能够满足够k个元素
            * 最后的index是插入位置
            */
            while(index>0 && (n-i+index >k) &&  (nums[i]>res[index-1] ) ){
                index--;
            }
            if(index<k){
                res[index++]=nums[i];
            }
        }
#ifdef DEBUG
        cout<<"k:"<<k<<"  "<<res.size()<<"  "<<nums.size()<<endl;
        print("infindmax",res);
#endif
        return res;
    }

    bool compare(vector<int>&nums1,int pos1,vector<int>&nums2,int pos2){
        while(pos1<nums1.size()  &&  pos2<nums2.size() && nums1[pos1]==nums2[pos2] ){
            pos1++;
            pos2++;
        }
        /**
        * 假如一个到结尾了,就先把另一个放进去
        *  5 3 2
        *  5 3 2 1   放入2的5 3 2 ,比较的时候是5 1 比较,依旧是正确的
        */
        if(pos2==nums2.size()  ||  (pos1<nums1.size() &&  nums1[pos1]>nums2[pos2] )){
            return true;
        }else{
            return false;
        }

    }

    void mergeVector(vector<int>&nums1,vector<int>&nums2,vector<int>&res){
#ifdef DEBUG
        cout<<"mergeVector:"<<nums1.size()<<"  "<<nums2.size()<<endl;
#endif // DEBUG


        if(nums1.size()==0){
            res.insert(res.begin(),nums2.begin(),nums2.end());
            return;
        }else if(nums2.size()==0){
            res.insert(res.begin(),nums1.begin(),nums1.end());
            return;
        }
        int pos1=0,pos2=0;
        while(pos1<nums1.size() || pos2<nums2.size()){
            res.push_back(compare(nums1,pos1,nums2,pos2)? nums1[pos1++] : nums2[pos2++] );
        }

        return ;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int>temp1,temp2,Maxn,res;
        for(int i=0;i<=k;i++){
            ///必须要>, 假如只是等于的话,可能下面k-i内部,会将i更新为nums1.size()
            ///然后在进入循环便是 i > nums1.size()
            ///假如是 >=的话,运行完直接跳出循环而不会merge
            if(i>nums1.size()){
                temp1=findMax(nums1,i);
                temp2=findMax(nums2,k-i);
                break;
            }else if((k-i)>nums2.size()){
                temp1=findMax(nums1,k-nums2.size());
                temp2=findMax(nums2,nums2.size());
                i=k-nums2.size();
            }else{
                temp1=findMax(nums1,i);
                temp2=findMax(nums2,k-i);
            }



            res.clear();
            mergeVector(temp1,temp2,res);
#ifdef DEBUG
            print("after merge",res);
#endif
            if(Maxn.size()==0){
                Maxn.insert(Maxn.end(),res.begin(),res.end());
            }else{
                for(int i=0;i<Maxn.size();i++){
                    if(Maxn[i]>res[i] ){
                        break;
                    }else if(Maxn[i] < res[i]){
                        Maxn.clear();
                        Maxn.insert(Maxn.end(),res.begin(),res.end());
                        break;
                    }
                }
            }
        }
        return Maxn;

    }
};




int main(){
    Solution s;
    vector<int>nums;
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(6);
    vector<int>vec= s.findMax(nums,3);
    print("test",vec);
    cout<<"-------------------------------------"<<endl;
    vector<int>nums1;
    vector<int>nums2;
    nums1.push_back(3);
    nums1.push_back(4);
    nums1.push_back(6);
    nums1.push_back(5);
    nums2.push_back(9);
    nums2.push_back(1);
    nums2.push_back(2);
    nums2.push_back(5);
    nums2.push_back(8);
    nums2.push_back(3);

    vector<int>result=s.maxNumber(nums1,nums2,5);
    cout<<"res:"<<endl;
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<"  ";
    }
    cout<<endl;
    cout<<"-------------------------------------"<<endl;
    nums1.clear();
    nums1.push_back(6);
    nums1.push_back(7);
    nums2.clear();
    nums2.push_back(6);
    nums2.push_back(0);
    nums2.push_back(4);
    result=s.maxNumber(nums1,nums2,5);
    cout<<"res:"<<endl;
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<"  ";
    }
    cout<<endl;

    cout<<"-------------------------------------"<<endl;
    nums1.clear();
    nums1.push_back(3);
    nums1.push_back(9);
    nums2.clear();
    nums2.push_back(8);
    nums2.push_back(9);
    result=s.maxNumber(nums1,nums2,3);
    cout<<"res:"<<endl;
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<"  ";
    }
    cout<<endl;

    cout<<"-------------------------------------"<<endl;
    nums1.clear();
    nums2.clear();
    nums2.push_back(1);
    result=s.maxNumber(nums1,nums2,1);
    cout<<"res:"<<endl;
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<"  ";
    }
    cout<<endl;

    cout<<"-------------------------------------"<<endl;
    nums1.clear();
    nums1.push_back(2);
    nums1.push_back(5);
    nums1.push_back(6);
    nums1.push_back(4);
    nums1.push_back(4);
    nums1.push_back(0);
    nums2.clear();
    nums2.push_back(7);
    nums2.push_back(3);
    nums2.push_back(8);
    nums2.push_back(0);
    nums2.push_back(6);
    nums2.push_back(5);
    nums2.push_back(7);
    nums2.push_back(6);
    nums2.push_back(2);
    result=s.maxNumber(nums1,nums2,15);
    cout<<"res:"<<endl;
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<"  ";
    }
    cout<<endl;
    cout<<"-------------------------------------"<<endl;
    nums1.clear();
    nums2.clear();
    nums1.push_back(1);
    nums1.push_back(2);
    result=s.maxNumber(nums1,nums2,2);
    cout<<"res:"<<endl;
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<"  ";
    }
    cout<<endl;
    cout<<"-------------------------------------"<<endl;

    nums1.clear();
    nums1.push_back(6);
    nums1.push_back(5);
    nums1.push_back(4);
    nums1.push_back(6);
    nums1.push_back(3);
    nums1.push_back(7);
    nums1.push_back(5);
    nums1.push_back(6);
    nums1.push_back(4);
    nums1.push_back(5);
    nums1.push_back(6);
    nums1.push_back(4);
    nums2.clear();
    nums2.push_back(8);
    nums2.push_back(8);
    nums2.push_back(6);
    nums2.push_back(0);
    result=s.maxNumber(nums1,nums2,16);
    cout<<"res:"<<endl;
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<"  ";
    }
    cout<<endl;
    cout<<"-------------------------------------"<<endl;

    return 0;
}



