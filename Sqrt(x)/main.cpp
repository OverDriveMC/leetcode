#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int left=0,right=INT_MAX;
        while(right>left+1){
            int mid=left+(right-left)/2;
            int res=x/mid;
            if(res ==mid){
                return mid;
            }else if(mid<=res){
                left=mid;
            }else{
                right=mid;
            }
            //cout<<left<<"  "<<right<<"   "<<res<<endl;
        }
        return left;
    }

};

int main(){
    Solution s;

    cout<<s.mySqrt(2147483647)<<endl;
    cout<<s.sqrt(2147483647)<<endl;

    for(int i=0;i<10;i++){
        cout<<i<<"  "<<s.mySqrt(i)<<endl;
    }

    return 0;
}
