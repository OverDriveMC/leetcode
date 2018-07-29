class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>>res=new ArrayList<>();
        List<Integer>list=new ArrayList<>();
        res.add(new ArrayList<>(list));
        Arrays.sort(nums);
        int size=1;
        for(int i=0;i<nums.length;i++){
            int start=0;
            if(i>0 && nums[i]==nums[i-1]){
                start=size;
            }
            size=res.size();
            for(int j=start;j<size;j++){
                list=new ArrayList<>(res.get(j));
                list.add(nums[i]);
                res.add(new ArrayList<>( list ));
            }
        }
        return res;
    }
}