/**
分治的策略,
分别计算左右最大的空间,最后在计算中间的最大的面积
时间复杂度O(nlgn),O(1)的空间复杂度
*/

class Solution {
    public int maxArea(int[]heights, int  start, int last){
        if(start>last){
            return 0;
        }
        if(start==last){
            return heights[start];
        }
        int mid=(start+last)/2;
        int leftMaxArea=maxArea(heights,start,mid);
        int rightMaxArea=maxArea(heights,mid+1,last);
        int leftpos=mid;
        int rightpos=mid+1;
        int midMaxArea=0;
		int height=heights[mid];
		 // Expand from the middle to find the max area containing height[m] and height[m+1]
		 /**
		 *注意横跨两边的时候,每次左右移动需要使用最小的height
		 */
		while(leftpos>=start && rightpos<=last){
			///使用左右之间最小的height,不可以单纯的拿左右两端比,还要和上一轮的height比较
			height=Math.min(height,Math.min(heights[leftpos],heights[rightpos]));
			midMaxArea=Math.max(height*(rightpos-leftpos+1),midMaxArea);
			///每次先移动的方向都是下一个位置更大一点的方向
			/// 例如：1 5 6 2  当前在5 6,下一次需要rightpos移动到2,这样才可以统计到所有的height
			if(leftpos==start || (rightpos<last && heights[leftpos-1]<heights[rightpos+1] )  ){
				rightpos++;
			}else{
				leftpos--;
			}
		}
		
		//System.out.println(start+"  "+mid+"   "+last+"   "+leftMaxArea+"   "+midMaxArea+"   "+rightMaxArea);
        return Math.max(Math.max(leftMaxArea,rightMaxArea),midMaxArea );
    }
    
    public int largestRectangleArea(int[] heights) {
        if(heights.length==0){
            return 0;
        }
        int maxn=maxArea(heights,0,heights.length-1);
        return maxn;
    }
	
	public static void main(String[]args){
		Solution s=new Solution();
		int[]heights={3,5,5,2,5,5,6,6,4,4,1,1,2,5,5,6,6,4,1,3};
		System.out.println(s.largestRectangleArea(heights));
	}
}