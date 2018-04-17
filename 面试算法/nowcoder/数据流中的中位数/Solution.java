import java.util.Comparator;
import java.util.PriorityQueue;
/**
添加offer
删除poll
堆顶peek
*/
public class Solution {
    private PriorityQueue<Integer> maxn=new PriorityQueue<Integer>(11,new Comparator<Integer>(){
        public int compare(Integer o1,Integer o2){
            return o2.compareTo(o1);
        }        
    });
    private PriorityQueue<Integer> minn=new PriorityQueue<Integer>();
    
    public void Insert(Integer num) {
        int size=maxn.size()+minn.size();
        if(size%2==1 ){
            //平分,将num和maxn[0]大的加入到minn中
            if( num> maxn.peek()){
                minn.offer(num);
            }else{
                minn.offer(maxn.peek());
                maxn.poll();
                maxn.offer(num);
            }
        }else{
            //将num与minn[0]小的加到maxn中
            if(minn.size()!=0 && num>minn.peek() ){
                maxn.offer( minn.peek() );
                minn.poll();
                minn.offer(num);
            }else{
                maxn.offer(num);
            }
        }
    }

    public Double GetMedian() {
        int size=maxn.size()+minn.size();
        if( size==0 ){
            return -1.0;
        }   
        if( size%2==1 ){
            return maxn.peek()*1.0;
        }else{
            return (minn.peek()+maxn.peek())/2.0;
        }
    }
}