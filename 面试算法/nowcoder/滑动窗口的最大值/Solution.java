/**
给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 
针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}，
 {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
*/

import java.util.ArrayDeque;
import java.util.ArrayList;

public class Solution {
    public ArrayList<Integer> maxInWindows(int [] num, int size)
    {
        ArrayList<Integer>res=new ArrayList<>();
        if(size==0){
            return res;
        }
		/**
		双端队列  
		假如添加顺序 1 2 3 4, 那么getFirst为1,getLast为4
		队列第一个位置保存当前窗口的最大值,当窗口滑动一次:
		1.判断当前最大值是否过期
		2.新增加的值从队尾开始比较,把所有比它小的值丢掉
		*/
        ArrayDeque<Integer>q=new ArrayDeque<>();
        for(int i=0;i<num.length;i++){
			//将新添加的值从队尾开始比较,因为新添加的值开始生效后,比它小的那些值都没有用了
			///注意,队列里维护的是下标
            while(!q.isEmpty() && num[i] > num[q.getLast() ] ){
                    q.pollLast();
            }
            q.add(i);
            if(i >=size-1){
				/**
				当到达size-1的位置开始之后,说明第一个滑动窗口里开始有值了,即为getFirst()元素
				*/
                res.add( num[ q.getFirst() ] );
				/**
				同时判断getFirst()位置在下一个元素添加的时候是否过期,假如过期,需要删掉
				*/
                if(q.getFirst()<=(i-size+1) ){
                	q.pollFirst();
                }
            }
        }
        return res;
    }
    public static void main(String[] args) {
		Solution s=new Solution();
		int arr[]={2,3,4,2,6,2,5,1};
		ArrayList<Integer> list=s.maxInWindows(arr, 3);
		list.forEach(x->System.out.println(x) );
	}
}