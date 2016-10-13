import java.util.*;
public class Solution {
    public void nextPermutation(int[] nums) {
		for(int i=nums.length-2 ;i>=0;i--){
			int minIndex=i;
			for(int j=i+1;j<nums.length;j++){
				if(nums[j]>nums[i]){
					if(minIndex==i){
						minIndex=j;
					}else if(nums[j]<nums[minIndex]){
						minIndex=j;
					}
				}
			}
			System.out.println("i:"+i+"  "+minIndex);
			if(minIndex!=i){
				swap(nums,i,minIndex);
				Arrays.sort(nums,i+1,nums.length);
				return ;
			}
		}
		for(int i=0;i<nums.length/2;i++){
			swap(nums,i,nums.length-i-1);
		}
		
    }
	
	public void swap(int[]nums,int a,int b){
		nums[a]=nums[a]^nums[b];
		nums[b]=nums[a]^nums[b];
		nums[a]=nums[a]^nums[b];
	}
	
	public static void main(String[]args){
		Solution s=new Solution();
		int a[]={3,2,1};
		s.nextPermutation(a);
		for(int i : a){
			System.out.print(i+"  ");
		}
		System.out.println();
		int b[]={1,3,2};
		s.nextPermutation(b);
		for(int i : b){
			System.out.print(i+"  ");
		}
		System.out.println();
		
		int c[]={4,2,0,2,3,2,0};
		s.nextPermutation(c);
		for(int i : c){
			System.out.print(i+"  ");
		}
		System.out.println();
	
	}
}