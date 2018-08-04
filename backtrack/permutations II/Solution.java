class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>>res=new ArrayList<>();
        if(nums==null || nums.length==0){
            return res;
        }        
        Arrays.sort(nums);
        boolean []used=new boolean[nums.length];
        backtrack(nums,res, new ArrayList<>(),used);
        return res;
    }
    void backtrack(int[]nums, List<List<Integer>>res, List<Integer>list, boolean[]used){
        if(list.size()==nums.length){
            res.add(new ArrayList<>(list));
            return ;
        }
        for(int i=0;i<nums.length;i++){
			/**
			两种情况需要continue,没有遍历的必要：
				一种是当前数已经添加过了
				另一种是当前数与前一个数是相同的,而前一个数还没有添加过
					(保证相同的数 出现在排列中的位置依然是 有序的,这样就不会出现重复的情况)
			*/
            if(used[i] ||  (i>0   &&  (nums[i]==nums[i-1] )   && !used[i-1] ) ){
                continue;
            }
            list.add(nums[i] );
            used[i]=true;
            backtrack(nums,res,list,used);
            list.remove(list.size()-1 );
            used[i]=false;
        }
    }
}