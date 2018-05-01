import java.util.PriorityQueue;

/**
优先队列
返回负数在前面
offer添加
poll 删除返回
peek 返回
*/
class Solution {
    public int[] kthSmallestPrimeFraction(int[] A, int K) {
        PriorityQueue<int[]>pq=new PriorityQueue<>((o1,o2)-> A[o1[0]] *A[o2[1]] - A[o1[1]]*A[o2[0]]);
        for(int i=0;i<A.length-1;i++){
        	pq.offer(new int[]{i,A.length-1});
        }
        for(int i=0;i<K-1;i++){
        	int[]t= pq.poll();
        	if(t[0]<t[1]-1){
        		pq.offer(new int[]{t[0],t[1]-1});
        	}
        }
        
        return new int[]{A[pq.peek()[0]],A[pq.peek()[1]]};
    }
    
    public static void main(String[] args) {
		Solution s=new Solution();
		int[]res=s.kthSmallestPrimeFraction(new int[]{1, 2,3,5},3) ;
		System.out.println(res[0]+"  "+res[1]);
	}
}