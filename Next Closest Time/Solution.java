import java.util.*;

/**
将时间映射到 [0,24*60 )之间的整数,
从cur时间逐渐网上增加,直到4个数都在set之中出现
*/

class Solution {
    public String nextClosestTime(String time) {
        int cur=Integer.parseInt(time.substring(0,2));
		cur=cur*60+Integer.parseInt(time.substring(3));
		Set<Character>set=new HashSet<Character>();
		for(char c : time.toCharArray()){
			if(c!=':'){
				set.add(c);
			}
		}		
		while(true){
			cur=(cur+1)%(24*60);
			// 19:34=1174
			///1174/60=19     1174%60=34
			///19/10=1  19%10=9   34/10=2   34%10=4  
			int digits[]=new int[]{cur/60/10,cur/60%10,cur%60/10,cur%60%10 };
			boolean flag=true;
			for(int dig : digits){
				/**
				* 这里要强转成char,否则会被当成整数
				*/
				if(!set.contains((char)(dig+'0'))){
					flag=false;
					break;
				}
			}
			if(flag){
				return String.format("%02d:%02d",cur/60,cur%60);
			}
			
		}
    }
/*	
	public static void main(String[]args){
		Solution s=new Solution();
		System.out.println(s.nextClosestTime("19:34"));
	}
*/
}