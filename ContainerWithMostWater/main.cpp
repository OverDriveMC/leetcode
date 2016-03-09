#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea1(vector<int>& height) {
        int maxArea=0;
        for(int i=0;i<height.size();i++){
            for(int j=i+1;j<height.size();j++){
                maxArea=max(maxArea,(j-i)*min(height[i],height[j]));
            }
        }
        return maxArea;
    }
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        ///防止[1,1]所以要赋个初值
        int maxArea=(j-i)*min(height[i],height[j]);
        while(i<j){
            if(height[i]<height[j]){
                int t=i+1;
                ///防止越界
                while(t<j&&height[t]<=height[i] ){
                    t++;
                }
                //cout<<"i="<<i<<"t="<<t<<endl;
                if(height[t]>height[i]){
                    i=t;
                }else{
                    break;
                }
            }else{
                int t=j-1;
                while(t>i&&height[t]<=height[j] ){
                    t--;
                }
               // cout<<"j="<<j<<"t="<<t<<endl;
                if(height[t]>height[j]){
                    j=t;
                }else{
                    break;
                }

            }
            //cout<<i<<"   "<<j<<endl;
            maxArea=max(maxArea,(j-i)*min(height[i],height[j]) );
        }
        return maxArea;
    }
};
int main(){
    int a[]={4,6,2,6,7,11,2};
    Solution s=Solution();
    vector<int>height=vector<int>(a,a+7);
    cout<<s.maxArea1(height)<<endl;
    cout<<s.maxArea(height)<<endl;
    int b[]={4,4,2,11,0,11,5,11,13,8};
    height=vector<int>(b,b+10);
    cout<<s.maxArea1(height)<<endl;
    cout<<s.maxArea(height)<<endl;
    return 0;
}
