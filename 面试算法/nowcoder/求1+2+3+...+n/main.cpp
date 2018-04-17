/*
求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
*/

class Solution {
public:
    int Sum_Solution(int n) {
        int ans=n;
		//使用短路表达式,当ans==0时终止递归
		///n >0时,计算sum+=sum_Solution(n-1)
        ans && (ans += Sum_Solution(n-1));
        return ans;
    }
};