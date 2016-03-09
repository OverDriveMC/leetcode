#include<bits/stdc++.h>

using namespace std;
/**
*1:首先假设我们找到能取最大容积的纵线为i,j(假定i<j),那么得到的
*最大容积=min(ai,aj)*(j-i)
*2:有这么一条性质：
*   ①：在j的右端没有一条线会比它高！假设存在
*k(j<k && ak>aj)，那么由ak>aj,所以min(ai,aj,ak)=min(ai,aj)
*所以由i,k构成的容器的容积C'=min(ai,aj)*(k-i)>C,与C是最值矛盾
*所以得证j的后边不会有比它还高的线
*   ②：同理，i的左边也没有一条线比他高！假设存在
*k(k<i && ak>ai),那么由ak>ai,所以min(ai,aj,ak)=min(ai,aj)
*所以由j,k构成的容器的容积C'=min(ai,aj)*(j-k)>C,与C是最值矛盾
*所以得证i的前边不会有比它还高的线
*这说明如果我们目前得到的候选：设为x,y两条线（x<y），那么
*能够得到比它更大容积的新的两条边必然在[x,y]区间内并且
*ax'>=ax,ay'>=ay
*3:所以我们从两头向中间靠拢，同时更新候选值；
*在收缩区间的时候优先从  x, y中较小的边开始收缩；
4:移动小的那一方的原因：
如果ai<aj
证明：
    对任意k<j
    因为k-i <j-i
    min(ak,ai)<ai<min(aj,ai)
    所以(k-i)*min(ak,ai)<(j-i)min(ai,aj)=(j-i)ai
所以此种情况，只能移动i
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int start=0,end=height.size()-1;
        int maxArea=0;
        while(start<end){
            maxArea=max(maxArea,
                        min(height[start],height[end])*(end-start));
            if(height[start]<height[end]){
                start++;
            }else{
                end--;
            }
        }
        return maxArea;
    }
};
int main(){
   int a[]={4,6,2,6,7,11,2};
    Solution s=Solution();
    vector<int>height=vector<int>(a,a+7);
    cout<<s.maxArea(height)<<endl;
    int b[]={4,4,2,11,0,11,5,11,13,8};
    height=vector<int>(b,b+10);
    cout<<s.maxArea(height)<<endl;

    return 0;
}
