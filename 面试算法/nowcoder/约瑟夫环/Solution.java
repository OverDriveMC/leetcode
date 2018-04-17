/**
有个游戏是这样的:首先,让小朋友们围成一个大圈。然后,他随机指定一个数m,让编号为0的小朋友开始报数。每次喊到m-1的那个小朋友要出列唱首歌,
然后可以在礼品箱中任意的挑选礼物,并且不再回到圈中,从他的下一个小朋友开始,继续0...m-1报数....这样下去....直到剩下最后一个小朋友,
请你试着想下,哪个小朋友会得到这份礼品呢？(注：小朋友的编号是从0到n-1)
*/
import java.util.*;
public class Solution {
    public int LastRemaining_Solution(int n, int m) {
		//采用链表模拟
        LinkedList<Integer>list=new LinkedList<>();
        for(int i=0;i<n;i++){
            list.add(i);
        }
        int cnt=0;
        while(list.size()>1){
			//下一个删除的对象下标
            cnt=(cnt+m-1)%list.size();
            list.remove(cnt);
        }
        return list.size()==1 ? list.get(0) : -1;
    }
}