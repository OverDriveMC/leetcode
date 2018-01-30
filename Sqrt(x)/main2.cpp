/**
采用牛顿迭代法:
	ans=(ans+x/ans)/2
	
   Guess Result        Quotient                             Average Result
          1            2 / 1 = 2                            (2 + 1) / 2 = 1.5
         1.5        2 / 1.5 = 1.3333                (1.3333 + 1.5) / 2 = 1.4167
       1.4167      2 / 1.4167 = 1.4118          (1.4167 + 1.4118) / 2 = 1.4142
        ... ...
*/

class Solution {
public:
    int mySqrt(int x) {
		double ans=x;
		double eps=1e-6;
		while(fabs(pow(ans,2 ) -x) >eps ){
			ans=(ans+x/ans)/2;
		}
		return ans;
    }
};