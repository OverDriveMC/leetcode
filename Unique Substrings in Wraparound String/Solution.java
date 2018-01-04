import java.util.*;
//去重
class Solution {
    public int findSubstringInWraproundString(String p) {
		if(p==null || p.length()==0){
			return 0;
		}
		int res=0;
		int curlength=1;
		List<String>vis=new ArrayList<>();
		StringBuilder sb=new StringBuilder();
		sb.append(p.charAt(0));
		for(int i=1;i<p.length();i++){
			if( (p.charAt(i) -p.charAt(i-1) ==1 ) || (p.charAt(i)=='a' && p.charAt(i-1)=='z')  ){
				curlength++;
				sb.append(p.charAt(i));
			}else{
				res+=addSubStringNumber(vis,sb.toString());
				sb.delete(0,sb.length());
				sb.append(p.charAt(i));
				curlength=1;
			}
		}
		res+=addSubStringNumber(vis,sb.toString());
		return res;
    }
	public static void main(String[]args){
		Solution s=new Solution();
		System.out.println(s.findSubstringInWraproundString("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz"));
		System.out.println(s.findSubstringInWraproundString("abcdefghijklmnopqrstuvwxyz"));
		System.out.println(s.findSubstringInWraproundString("zab"));
		System.out.println(s.findSubstringInWraproundString("abdezabcde"));
		
		/// a-z a-z之间会重复，，，所以上一种方法不行
		System.out.println(s.findSubstringInWraproundString2("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz"));
		System.out.println(s.findSubstringInWraproundString2("abcdefghijklmnopqrstuvwxyz"));
		System.out.println(s.findSubstringInWraproundString2("zab"));
		System.out.println(s.findSubstringInWraproundString2("abdezabcde"));
	}
	public int addSubStringNumber(List<String>vis,String s){
		int num=(1+s.length()) * s.length() /2;
		
		Iterator<String>iter=vis.iterator();
		while(iter.hasNext()){
			String str=iter.next();
			if(str.contains(s)){
				return 0;
			}else if(s.contains(str)){
				num-=(1+str.length())*str.length()/2;
				iter.remove();
				
			}
			
		}
		//说明所有它是最长的,添加进去
		vis.add(s);
		return num;
	}
/**
对于符合条件的子串(符合条件指的是该串为p的子串),只需要记录"长度"和"结尾字符"这两个关键字就可以唯一确定这个子串
以abcdpjiezabc为例,两个符合条件的极大子串为abcd  zabc
对于abcd,记录[1,a] [2,b] [3,c] [4,d]
    无需记录[1,b] [2,c]等等,因为[2,b][3,c]天然的包含了长度比他们小的子串
对于zabc,记录[1,z] [2,a] [3,b] [4,c]

对于[1,a],因为哈希表中已经存在[2,a]所以[1,a]所表示的子串已经在[2,a]中被统计,为了避免重复统计,只需要记录
某个字母结尾的,长度最大的那个符合条件的子串长度就可以了,假设哈希表中对应某个字母p的最长子串长度为k,因为长为
k的字符串,有k个子串以P结尾的,那么需要给最终答案加上k,这种统计方法把所有可能的子串都记录其中,并且不会重复
综上,算法时间复杂度为遍历数据和更新哈希表的时间复杂度:O(N),空间复杂度为O(1)
*/	
	public int findSubstringInWraproundString2(String p) {
		if(p==null || p.length()==0){
			return 0;
		}
		int a[]=new int[26];
		for(int i=0;i<26;i++){
			a[i]=0;
		}
		int res=0;
		int curlength=0;
		for(int i=0;i<p.length();i++){
			if(i>0 && ( ( p.charAt(i) -p.charAt(i-1) ==1  ) || (p.charAt(i) =='a'  && p.charAt(i-1) =='z')  )   ){
				curlength++;
			}else{
				curlength=1;
			}  
			int index=p.charAt(i) -'a';
			a[ index ] =Math.max( curlength, a[index]  );
		}
		
		for(int i=0;i< 26;i++){
			res+=a[i];
		}
		return res;
    }
	
	
	
}

