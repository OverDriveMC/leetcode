#include <bits/stdc++.h>

using namespace std;
/**
*至多有2个数的个数超过n/3
*3* n/3 =n 假如有3个数,整体个数会超过n
*记录两个数,假如出现则次数 +1, 否则次数 -1
*例如有100个数, 假如只有一个数1出现次数为 34, 其余的数出现次数皆为1
*1会加34次, 但是减的次数不会超过34次,因为假如m=1,会有减法落在n身上,更新n
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        /**
        不能这样判断,例如[2 2],只能返回一个2
        if(nums.size()<=2){
            return nums;
        }
        */
        vector<int>res;
        int m=0,n=0,cm=0,cn=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==m){
                cm++;
            }else if(nums[i]==n){
                cn++;
            }else if(cm==0){
                m=nums[i];
                cm=1;
            }else if(cn==0){
                n=nums[i];
                cn=1;
            }else{
                cm--;
                cn--;
            }
        }
        cm=0,cn=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==m){
                cm++;
            }else if(nums[i]==n){
                cn++;
            }
        }
        if(cm> nums.size()/3 ){
            res.push_back(m);
        }
        if(cn >nums.size()/3){
            res.push_back(n);
        }
        return res;
    }
};
int main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(1);
    Solution s;
    vector<int>res= s.majorityElement(nums);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
}
