/**
在数组中寻找最长子序列：里面最大值和最小值正好相差1
Input: [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].

*/



/**
getOrDefault(key,0):得不到返回0
使用Long的原因
indLHS(new int[]{-2147483648 , 2147483647});
//2147483647 + 1 = -2147483648 , and we don't want that.
*/
class Solution {
    public int findLHS(int[] nums) {
        Map<Long,Integer>map=new HashMap<>();
        for(long i : nums){
            map.put(i, map.getOrDefault(i,0)+1);
        }
        int maxn=0;
        for(Long key : map.keySet()){
            if(map.containsKey(key+1)){
                maxn= Math.max(maxn, map.get(key) +map.get(key+1) );   
            }
        }
        return maxn;
    } 
}



class Solution {
    public int findLHS(int[] nums) {
        Arrays.sort(nums);
        int maxn=0;
        int cur=0;
        int pre=-1;
        int i=0;
        while(i< nums.length){
			/**
			注意:cur从1开始,因为例如：
						1 1 1  2
						0 1 2  3
			nums[0]==nums[1]     nums[1]==nums[2]   nums[2]!=nums[3]
			实际cur有3个
 			*/
            cur=1;
            while( ( i+1<nums.length ) &&  (nums[i]==nums[i+1])     ){
               cur++;
               i++;
            }
			/**
			判断之前的数量是否为-1
			只有比它小1的元素存在的时候才更新maxn
			*/
            if(pre!=-1){
                maxn=Math.max(maxn,pre+cur);
            }
			//如果下一个元素比它正好大一,那么pre是有值的,即为cur,否则是pre=-1
			//表示不计入长度里面
            if(i+1!=nums.length &&  (nums[i+1]-nums[i]==1 )  ){
                pre=cur;
            }else{
                pre=-1;
            }
            i++;
        }
        return maxn;
    }
}