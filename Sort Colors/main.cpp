#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int validZPos=0;
        int validTPos=nums.size()-1;

        for(int i=0;i<=validTPos;i++){
            if(nums[i]==0 ){
                if(i!=validZPos){
                    swap(nums[i],nums[validZPos]);
                    i--;
                }
                validZPos++;
            }
            if(nums[i]==2 ){
                if(i!=validTPos){
                    swap(nums[i],nums[validTPos]);
                    i--;
                }
                validTPos--;
            }
        }
    }
};


int main(){
    vector<int>vec;
    vec.push_back(1);
    vec.push_back(0);
    vec.push_back(2);
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(0);
    vec.push_back(2);

    Solution s;
    s.sortColors(vec);
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<endl;
    }
    cout<<endl<<endl;
    vec.clear();
    vec.push_back(1);
    vec.push_back(0);
    s.sortColors(vec);
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<endl;
    }
    return 0;
}
