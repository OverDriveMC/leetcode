/**
array indexing:用于试图将乱序的1~n顺序的重新放入这个数组
for(int i=0;i<nums.length;i++){
	while(nums[i]-1!=i){
		swap(nums,i,nums[i]-1);
	}
}
对于处在位置i上的数字nums[i],如果nums[i]!=i+1,说明它没有放在正确的位置上
所以交换nums[i]和nums[nums[i]-1],那么原先的nums[i]就被放在了正确的位置,而位置i上又有了
一个新数,while循环重复以上操作,直至位置i上有正确的数,外层的for循环将保证所有位置都存放
对应的正确的数,时间复杂度是O(n)
而此题有所不同,因为nums存放的不是1~n,上述算法中的while循环条件nums[i]!=i+1可能无法满足而死循环
改动的方法是在外面套一层nums:
for(int i=0;i<nums.size();i++){
	while(nums[i] != nums[nums[i]-1])
		swap(nums,i,nums[i]-1)
}
这样的话,重复的两个数字最后会放在：一个在其应该的位置,一个在missing number的位置
最后遍历一遍nums,找到nums[i]-1!=i的那个位置,实际位于i位置的那个元素就是重复的数字
本应位于i位置上的那个元素就是missing number
*/

class Solution {
    public int[] findErrorNums(int[] nums) {
        for(int i=0;i<nums.length;i++){
			while(nums[i]!=nums[nums[i]-1]){
				swap(nums,i,nums[i]-1);
			}
		}
		for(int i=0;i<nums.length;i++){
			if(nums[i]!=(i+1)){
				return new int[]{nums[i],i+1};
			}
		}
        return null;
    }
	public void swap(int[]nums,int i,int j){
		int temp=nums[i];
		nums[i]=nums[j];
		nums[j]=temp;
	}
}