#include<bits/stdc++.h>

using namespace std;
class Solution {

public:
    int inf=0x7fffffff;
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<3){
           return 0;
        }
        sort(nums.begin(),nums.end());
        int closet=inf;
        int currentcloset;
        for(int i=0;i<nums.size()-2;i++){
            currentcloset=getCloset(nums,i+1,target);
            if(currentcloset==target){
                return target;
            }
            if(closet==inf){
                closet=currentcloset;
                continue;
            }
            closet=abs(closet-target)>abs(currentcloset-target)
                    ? currentcloset : closet;

        }
        return closet;
    }
    int getCloset(vector<int>& nums,int start,int target){
        int x=start,y=nums.size()-1;
        int closet=0x7fffffff;
        while(x<y){
            int sum=nums[x]+nums[y]+nums[start-1];
            if(sum==target){
                return target;
            }else if(sum<target){
                x++;
            }else{
                y--;
            }
            if(closet==inf){
                closet=sum;
                continue;
            }
            closet=abs(sum-target)>abs(closet-target)
                    ? closet : sum;
        }
        return closet;
    }
};
int main(){
    Solution s;
    vector<int>vec;
    //-1 2 1 -4
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(0);
    cout<<s.threeSumClosest(vec,100)<<endl;

    /**
    *可以用下面的来保证不会溢出，这样就不用特判
    */
    cout<<numeric_limits<int>::max()<<endl;
    cout<<numeric_limits<int>::min()<<endl;
    cout<<abs(0x7fffffff+1)<<endl;
    cout<<numeric_limits<int>::min()+1<<endl;
    return 0;
}
