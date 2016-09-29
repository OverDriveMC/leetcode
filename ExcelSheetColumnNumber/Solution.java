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