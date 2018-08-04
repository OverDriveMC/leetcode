class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res=new ArrayList<>();
        if(nums==null || nums.length==0){
            return res;
        }
        
        boolean []used=new boolean[nums.length];
        backtrack(nums,res,new ArrayList<>(), used);
        return res;
    }
    public void backtrack(int[]nums, List<List<Integer>>res, List<Integer>list, boolean[]used ){
        if(list.size()==nums.length){
            res.add(new ArrayList<>(list));
            return ;
        }
		/**
		求排列的时候,每次都要从位置0开始,每次从所有数字里选择没有出现过的
		*/
        for(int i=0;i<nums.length;i++){
            if(used[i]){
                continue;
            }
            list.add(nums[i]);
            used[i]=true;
            backtrack(nums,res,list,used);
            list.remove(list.size()-1);
            used[i]=false;
        }
        
    }
}