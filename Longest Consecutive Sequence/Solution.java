class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer>set=new HashSet<>();
        for(int num  : nums){
            set.add(num);
        }
        int maxlength=0;
        for(int num : nums){
            ///1 2 3 4
            ///通过这里保证只有num==1的时候会进入循环内部(因为判断了num-1在不在内部)
            ///其余的会直接continue
            if(set.contains(num-1)){
                continue;
            }
            ///判断可以延续到哪里
            int length=1;
            for(int i=num+1; ;i++){
                if(!set.contains(i)){
                    break;
                }
                length++;
            }
            maxlength=Math.max(maxlength,length);
        }
        return maxlength;
    }
}
