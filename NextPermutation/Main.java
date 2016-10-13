import java.util.*;
public class Main {
    public void nextPermutation(int[] nums) {
		int pos=0;
		for(int i=nums.length-1;i>0;i--){
			/**
			*找到第一个 num[i]>num[i-1]的位置
			* i之后说明是降序的,只要将i-1所在的数用右边最小的大于它的数替换下来
			*然后逆序过来即可。
			*个位、十位肯定是优先排在前面的位置
			*/
			if(nums[i]>nums[i-1]){
				pos=i;
				swap(nums,i-1,binarySearch(nums,i,nums.length-1,nums[i-1]));
				break;
			}
		}
		int last=nums.length-1;
		while(pos<last){
			swap(nums,pos,last);
			pos++;
			last--;
		}
    }
	/**
	* 循环不变式:假如存在比target大的数,那么必有num[begin]>target,num[right]可能大于
	*循环中:num[mid]>target  num[begin...mid]>target 数组减少长度为 mid-begin
	*       只有当mid==begin时才不会减少，这种情况只有在begin==right或者begin==right-1时才会出现
	*		所以当begin+1<last时循环退出
	*		当num[mid]<=target时，num[mid...last]<=target,所以返回位置一定不再这个范围内,
	*		可以直接last=mid-1, 数组减少长度为  last-mid一定大于0
	*所以最后退出的时候一定是begin+1==right,最后num[mid]<=target
	*所以  num[begin]>target  num[right]可能大于target，所以特判一下
	*/
	public int binarySearch(int []num,int begin,int last,int target){
		int mid=begin;
		while(last>begin+1){
			mid=begin+(last-begin)/2;
			if(num[mid]>target){
				begin=mid;
			}else if(num[mid]<=target){
				last=mid-1;
			}
		}
		if(num[last]>target){
			return last;
		}else{
			return begin;
		}
	}
	public void swap(int[]nums,int a,int b){
		if(a!=b){
			nums[a]=nums[a]^nums[b];
			nums[b]=nums[a]^nums[b];
			nums[a]=nums[a]^nums[b];
		}
	}
	public static void main(String[]args){
		Main s=new Main();
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