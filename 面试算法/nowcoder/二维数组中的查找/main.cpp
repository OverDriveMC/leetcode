/**
从右上角搜索(不从左上角开始搜寻:左上角向右和向下都是递增,那么对于一个点,对于向右和右下会产生一个岔路;
如果选择从右上角搜索的话,那么当target<a[row][col],那么target必定在元素a所在行的左边,即col--
当target大于元素a[row][col]时,那么target必定在元素a所在列的下边,即row++
)
*/

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.size()==0 || array[0].size()==0){
            return false;
        }
        int x=0,y=array[0].size()-1;
        while(true){
            if(x<0 || x>=array.size() || y<0 || y>=array[x].size()){
                return false;
            }
            if(array[x][y]==target ){
                return true;
            }else if(array[x][y]<target){
                x++;
            }else if(array[x][y]>target){
                y--;
            }
        }
    }
};