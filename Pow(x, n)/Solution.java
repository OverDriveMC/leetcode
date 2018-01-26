class Solution {
	/**
	需要先转化成long,然后使用快速幂
	*/
    public double myPow(double x, int n) {
		long pow=n;
        if(n==0){
            return 1;
        }else if(n<0){
            pow=-pow;
            x=1/x;
        }
		System.out.println(pow);
        double res=1;
        while(pow!=0){
            if(pow%2!=0){
                res*=x;
            }
            x*=x;
            pow>>=1;
        }
        return res;
    }
	
	public static void main(String[]args){
		Solution s=new Solution();
		System.out.println(s.myPow(1,-2147483648));
	}
}