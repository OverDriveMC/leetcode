/**
* 通过 num & (num-1) 判断是不是2的power
* 因为power(4)需要保证1的位置总是出现在奇数位置
* 4^0=1   4^1=100   4^2=10000
* 所以与0x55555555
*/

class Solution {
public:
    bool isPowerOfFour(int num) {
        //注意符号 优先级
        return (num>0) && ((num & (num-1)) ==0) && ((num & 0x55555555 ) ==num );
    }
};