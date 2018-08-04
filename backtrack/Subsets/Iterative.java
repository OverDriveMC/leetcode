class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer> >res=new ArrayList<>();
        List<Integer>list=new ArrayList<>();
        res.add(list);
        for(int num : nums){
            int size=res.size();
			/**
			每次将当前元素添加进入已有的集合,
			组成新的集合
			[1,2,3]
第一轮 [[]]         		1====> [[]  [1]]
第二轮 [[] [1]]     		2====> [[] [1] [2] [1,2] ]
第三轮 [[] [1] [2] [1,2] ]  3====> [[] [1] [2] [1,2] [3] [1,3] [2,3] [1,2,3]] 
			*/
            for(int i=0;i<size;i++){
                List<Integer>temp=new ArrayList<>(res.get(i));
                temp.add(num);
                res.add(temp);
            }
        }
        return res;
    }
}