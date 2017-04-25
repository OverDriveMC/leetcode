class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<=1) return 0;
        int maxheight=height[0],maxpos=0;
        //首先找到最高点的位置与最高点
        for(int i=1;i<height.size();i++){
            if(height[i]>maxheight){
                maxheight=height[i];
                maxpos=i;
            }
        }
        //分别从左右两个方向往最高点搜索,一直更新到搜索点的最大值,因为没有到最高点,所以后面肯定有比当前最高点高的位置(最高点)
        //所以一定能形成凹字形。
        int cmheight=height[0];
        int area=0;
        for(int i=1;i<maxpos;i++){
            if(cmheight<height[i]){
                cmheight=height[i];
            }else{
                area+=(cmheight-height[i]);
            }
        }
        cmheight=height[height.size()-1];
        for(int i=height.size()-2;i>maxpos;i--){
            if(cmheight<height[i]){
                cmheight=height[i];
            }else{
                area+=(cmheight-height[i]);
            }
        }
        return area;
    }
};