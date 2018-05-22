/**
Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...
Example 1:

Input: "A"
Output: 1
Example 2:

Input: "AB"
Output: 28
Example 3:

Input: "ZY"
Output: 701
26进制

AB:  ('A'-'A'+1)*26+('B'-'A'+1)
每次加个1即可

*/


public class Solution {
    public int titleToNumber(String s) {
		int  res=0;
		for(int i=0;i<s.length();i++){
			res=res*26+(s.charAt(i)-'A'+1);
		}
		return res;
    }
	public int titleToNumber2(String s) {
		char cc[]=s.toCharArray();
		int  res=0;
		for(int i=0;i<cc.length;i++){
			res=res*26+(cc[i]-'A'+1);
		}
		return res;
    }
	
	public static void main(String[]args){
		Solution s=new Solution();
		long time=System.currentTimeMillis();
		sop(s.titleToNumber2("AAAAAA"));
		sop(s.titleToNumber2("AAAAAA"));
		sop(s.titleToNumber2("AAAAAA"));
		sop(s.titleToNumber2("AAAAAA"));
		long end1=System.currentTimeMillis();
		sop(s.titleToNumber("AAAAAA"));
		sop(s.titleToNumber("AAAAAA"));
		sop(s.titleToNumber("AAAAAA"));
		sop(s.titleToNumber("AAAAAA"));
		long end2=System.currentTimeMillis();
		sop((end1-time)+"   "+(end2-end1));
	}
	public static void sop(Object obj){
			System.out.println(obj);
	}
}