/**
输出不重复的子集
Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer> >res=new ArrayList<>();
        backtrack(nums,res,new ArrayList<>(), 0);
        return res;
    }
    void backtrack(int[]nums, List<List<Integer> >res, List<Integer>list, int start){
        res.add(new ArrayList<>(list));
        for(int i=start;i<nums.length;i++){
            //循环的i代表当前下一个需要添加的元素,在它前面的元素都已经被删除
            //这个元素要作为start位置开始往后添加
            //(当i!=start的时候,说明上一个添加的元素已经被删除了,已经完成了所有包含它的遍历)
            
            if(  i>start &&  (nums[i]==nums[i-1])){
                continue;
            }
            list.add(nums[i]);
            backtrack(nums,res,list,i+1);
            list.remove(list.size()-1);
        }
    }
}