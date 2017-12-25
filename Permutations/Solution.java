import java.util.*;


class Solution {
    public List<List<Integer>> permute(int[] nums) {
		List<List<Integer>>res=new ArrayList<>();
		int vis[]=new int[nums.length];
		for(int i=0;i<vis.length;i++){
			vis[i]=0;
		}
		List<Integer>temp=new ArrayList<>();
		dfs(res,vis,nums,temp);
		return res;
    }
	public void dfs(List<List<Integer>>res,int []vis,int []nums,List<Integer>temp){
		if(nums.length==temp.size()){
			/**
			* 这里需要先建一个新的List,然后将元素添加进来
			*/
			List<Integer>t=new ArrayList<>(temp);
			res.add(t);
		}else{
			for(int i=0;i<nums.length;i++){
				if(vis[i]==0){
					vis[i]=1;
					temp.add(nums[i]);
					dfs(res,vis,nums,temp);
					/**
					* 计算完加入该元素的情况,需要将之删除
					* 并将vis 标记重置
					*/
					temp.remove(temp.size()-1);
					vis[i]=0;
				}
			}
			
		}
		
	}
/*	
	public static void main(String[]args){
		Solution s=new Solution();
		int[]nums={1,2,3};
		List<List<Integer>>res=s.permute(nums);
		for(List<Integer>list : res){
			for(Integer i : list){
				System.out.print(i);
			}
			System.out.println();
		}
	}
*/
}