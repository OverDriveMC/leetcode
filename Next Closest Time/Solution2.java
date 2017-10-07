import java.math.*;
import java.util.*;
/**
For example, if we have start = 720 (ie. noon), then times like 12:05 = 725 means that (725 - 720) % (24 * 60) = 5 seconds have elapsed; 
while times like 00:10 = 10 means that (10 - 720) % (24 * 60) = -710 % (24 * 60) = 730 seconds have elapsed.

Also, we should make sure to handle cand_elapsed carefully. When our current candidate time cur is equal to the given starting time, 
then cand_elapsed will be 0 and we should handle this case appropriately.

*/
class Solution2 {
    public String nextClosestTime(String time) {
		int cur=Integer.parseInt(time.substring(0,2))*60;
		cur+=Integer.parseInt(time.substring(3));
		Set<Integer>set=new HashSet<Integer>();
		for(char c : time.toCharArray()){
			if(c!=':'){
				set.add(c-'0');
			}
		}
		int maxelapsed=24*60;
		///这里需要赋值为初始值,因为会出现例如11:11这种数据,打印原始数据即可
		int ans=cur;
		for(int h1 : set){
			for(int h2:set){
				///hours<24 并且mins<60
				if(h1*10+h2<24){
					for(int m1:set){
						for(int m2:set){
							if(m1*10+m2<60){
								int curtime=(h1*10+h2)*60+(m1*10+m2);
								int curelapsed=Math.floorMod(curtime-cur,24*60);
								//time != start
								//同时是最小的 (time-start) % (24*60)
								if(curelapsed>0 && curelapsed<maxelapsed){
									System.out.println(h1+"  "+"  "+h2+"  "+m1+"  "+m2);
									ans=curtime;
									maxelapsed=curelapsed;
								}
							}
						}
					}
				}
			}
		}
		return String.format("%02d:%02d",ans/60,ans%60);
    }
	public static void main(String[]args){
		Solution2 s=new Solution2();
		System.out.println(s.nextClosestTime("22:23"));
	}
}