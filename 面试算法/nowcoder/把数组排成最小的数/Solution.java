import java.util.Arrays;
import java.util.Comparator;

public class Solution {
    public String PrintMinNumber(int [] numbers) {
        if(numbers==null || numbers.length==0){
            return "";
        }
        String []strs=new String[numbers.length];
        for(int i=0;i<strs.length;i++){
        	strs[i]=String.valueOf(numbers[i]);
        }
		/**
		使用Lambda表达式
		*/
        Arrays.sort(strs,(String a,String b) -> (a+b).compareTo(b+a));
        /*
		或者重写Comparator接口
        Arrays.sort(strs,new Comparator<String>(){
        	public int compare(String a, String b){
        		a+=b;
        		b+=a;
        		return a.compareTo(b);
        	}
        });
        */
        StringBuilder sb=new StringBuilder();
        for(int i=0;i<numbers.length;i++){
            sb.append(strs[i]);
        }
        return sb.toString();
    }
    
    
}