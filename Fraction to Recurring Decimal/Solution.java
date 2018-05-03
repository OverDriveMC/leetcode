/**
计算 numerator / denominator
假如有循环节,表示出来循环

需要提前考虑是否会出现循环节,如果无限不循环那？
Example 1:

Input: numerator = 1, denominator = 2
Output: "0.5"
Example 2:

Input: numerator = 2, denominator = 1
Output: "2"
Example 3:

Input: numerator = 2, denominator = 3
Output: "0.(6)"

*/

import java.util.HashMap;
import java.util.Map;

class Solution {
    public String fractionToDecimal(int numerator, int denominator) {
		//判断是否除0
        if(denominator==0){
            throw new RuntimeException("除0");
        }
		//结果为0
        if(numerator==0){
            return "0";
        }
        StringBuilder res=new StringBuilder();
        //判断正负号
		if((numerator>0) != (denominator>0)){
            res.append("-");
        }
		//-2^31转换为正数会越界
        long num=Math.abs((long)numerator);
        long den=Math.abs((long) denominator);
		//先求整数部分
        res.append(num/den);
        if(num%den==0){
            return res.toString();
        }
        num=num%den;
        res.append(".");
		//开始计算小数部分
		//使用map来判断当前的被除数是否出现过,假如出现过,后面便是循环节(因为除数  被除数都一样)
        Map<Long,Integer>map=new HashMap<Long,Integer>();
		//向push进被除数
        map.put(num,res.length());
/**
例如1/6 
进入循环前  num=1   res:0.  map 1=>2
第一轮:     res:0.1    num=4  判断没有出现过   map 1=>2  4=>3
第二轮      res:0.16   num=4  判断出现过    第3位添加( 结尾push) 

*/		
		

        while(num!=0){
			//每次*10,然后将商放入,如果发现被除数曾经出现,那么直接说明出现循环节
        	num*=10;
            res.append(num/den);
            num%=den;
        	if(map.containsKey(num)){
                int idx=map.get(num);
                res.insert(idx,'(');
                res.append(')');
                break;
            }
        	map.put(num,res.length());
        }
        return res.toString();
    }
    
    public static void main(String[] args) {
		Solution s=new Solution();
		System.out.println(s.fractionToDecimal(1, 6));
		System.out.println(s.fractionToDecimal(1, 2));
		System.out.println(s.fractionToDecimal(2, 1));
	}
}