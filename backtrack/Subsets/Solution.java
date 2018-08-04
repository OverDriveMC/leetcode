class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>>res=new ArrayList<>();
        backtrack(nums,res,new ArrayList<>(), 0);
        return res;
    }
    public void backtrack(int[]nums, List<List<Integer>>res, List<Integer>list, int index ){
        res.add(new ArrayList<>(list) );
        for(int i=index;i<nums.length;i++){
            list.add(nums[i]);
            backtrack(nums,res,list, i+1);
            list.remove(list.size()-1);
        }
    }
}