import java.util.ArrayList;
import java.util.List;


class People{
	int id;

	public People(int id) {
		super();
		this.id = id;
	}
	
}

class Solution {
	
	void test(){
		List<People>list=new ArrayList<>();
		list.add(new People(2));
		/**
		 * 这种构造属于传reference,操作的还是同一个
		 */
		List<People>nlist=new ArrayList<>(list);
		nlist.get(0).id=5;
		System.out.println(list.get(0).id);
		
		/**
		 * 基本数据类型可以这样构造
		 */
		List<Integer>t1=new ArrayList<>();
		t1.add(3);
		List<Integer>t2=new ArrayList<>(t1);
		t2.set(0, 5);
		System.out.println(t1.get(0)+"   "+t2.get(0));
	}
	
    public List<List<Integer>> subsets(int[] nums) {
		List<List<Integer> >res=new ArrayList<>();
		backtrack(nums,new ArrayList<Integer>(),0,res );
		return res;
    }
	
	public void backtrack(int[]nums, List<Integer>cur, int index, List<List<Integer>>res){
		res.add(new ArrayList<>(cur) );
		/**
		 * 可以打出来res的结果看过程
		 * [[], [1], [1, 2], [1, 2, 3], [1, 3], [2], [2, 3], [3]]
		 */
		for(int i=index;i<nums.length;i++){
			cur.add(nums[i]);
			backtrack(nums, cur, i+1, res);
			cur.remove(cur.size()-1 );
		}
	}
	
	public static void main(String[] args) {
		
		int []nums={1,2,3};
		Solution s=new Solution();
		
		s.test();
		System.out.println(s.subsets(nums));
	}
}