import java.util.ArrayList;
import java.util.Collections;
import java.util.List;



class Interval {
	int start;
	int end;
	Interval() { start = 0; end = 0; }
	Interval(int s, int e) { start = s; end = e; }
	public int getStart() {
		return start;
	}
	public void setStart(int start) {
		this.start = start;
	}
	public int getEnd() {
		return end;
	}
	public void setEnd(int end) {
		this.end = end;
	}
	
	
}

public class Solution {
    public List<Interval> merge(List<Interval> intervals) {
		///这样copy假如修改copy里的元素同时也会修改原有的容器里的元素
/*
		List<Interval>copy=new ArrayList<Interval>(intervals);
		System.out.println(copy.get(0).start);
		copy.get(0).start=5;
		System.out.println(intervals.get(0).start);
*/
    	List<Interval>res=new ArrayList<>();
    	if(intervals.isEmpty()){
    		return res;
    	}
		List<Interval>copy=new ArrayList<Interval>();
		for(Interval val : intervals){
			copy.add(new Interval(val.start,val.end));
		}
/**
按照start的顺序排序,然后根据end的大小进行合并

*/
		Collections.sort(copy,(lhs,rhs)->{
			if(lhs.start==rhs.start)
				return lhs.end-rhs.end;
			else
				return lhs.start-rhs.start;
						
		});
		//copy.forEach(val -> System.out.println(val.start+"   "+val.end ));
		int start=copy.get(0).start;
		int end=copy.get(0).end;
		for(Interval val : copy){
			if(val.start>end){
				res.add(new Interval(start,end));
				start=val.start;
				end=val.end;
			}else{
				// [1,4]  [2,3]
				//需要判断下当前的end是否比val的end往后
				end=Math.max(val.end, end);
			}
		}
		res.add(new Interval(start,end));
		return res;
    }
	
	
	public static void main(String[]args){
		Solution s=new Solution();
		List<Interval>list=new ArrayList<>();
		list.add(new Interval(2,6));
		list.add(new Interval(1,3));
		list.add(new Interval(8,10));
		list.add(new Interval(15,18));
		
		s.merge(list).forEach(val -> System.out.println(val.start+"  "+val.end));
	}
}