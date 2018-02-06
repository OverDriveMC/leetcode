import java.util.*;
/**
For every bar ‘x’, we calculate the area with ‘x’ as the smallest bar in the rectangle. If we calculate such area for every bar ‘x’ and find the maximum of all areas, 
our task is done. 
How to calculate area with ‘x’ as smallest bar? 
We need to know index of the first smaller (smaller than ‘x’) bar on left of ‘x’ and index of first smaller bar on right of ‘x’. 
Let us call these indexes as ‘left index’ and ‘right index’ respectively.
We traverse all bars from left to right, maintain a stack of bars. Every bar is pushed to stack once. 
A bar is popped from stack when a bar of smaller height is seen. When a bar is popped, we calculate the area with the popped bar as smallest bar. 
How do we get left and right indexes of the popped bar – the current index tells us the ‘right index’ and index of previous item in stack is the ‘left index’. 
Following is the complete algorithm.

1) Create an empty stack.

2) Start from first bar, and do following for every bar ‘hist[i]’ where ‘i’ varies from 0 to n-1.
……a) If stack is empty or hist[i] is higher than the bar at top of stack, then push ‘i’ to stack.
……b) If this bar is smaller than the top of stack, then keep removing the top of stack while top of the stack is greater. Let the removed bar be hist[tp]. 
Calculate area of rectangle with hist[tp] as smallest bar. For hist[tp], the ‘left index’ is previous (previous to tp) item in stack and ‘right index’ is ‘i’ (current index).

3) If the stack is not empty, then one by one remove all bars from stack and do step 2.b for every removed bar.

*/
class Solution2 {
    public int largestRectangleArea(int[] heights) {
		/**
		* 栈里存储heights数组的下标
		* 栈里存储的下标代表的height保证是不下降序列
		*/
        Stack<Integer>s=new Stack<>();
        int maxArea=0;
		int i=0;
        while(i<heights.length){
			//注意这里要有=,只有比他小的时候才出栈(相等的时候,因为right位置直到比它小的位置,所以也要入栈)
            if(s.empty() || heights[s.peek() ] <=heights[i] ){
                s.push(i++);
            }else{
                int index=s.peek();
                s.pop();
				///该高度能延伸的最右的位置即是i,最左边的位置即是栈顶元素所在的位置(假如栈顶没有其它元素,说明当前元素即是最小的元素)
                maxArea=Math.max(maxArea, heights[index]*( s.empty() ? i : (i-s.peek()-1) ) );
            }
        }
        int n=heights.length;
        while(!s.empty()){
            int index=s.peek();
            s.pop();
            maxArea=Math.max(maxArea, heights[index]*( s.empty() ? n : (n-s.peek()-1) ) );
        }
        return maxArea;
    }
	
	public static void main(String[]args){
		Solution2 s=new Solution2();
		int[]heights={2,1,5,6,2,3};
		System.out.println(s.largestRectangleArea(heights));
	}	
}