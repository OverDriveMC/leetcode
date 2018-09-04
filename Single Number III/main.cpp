class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xors=nums[0];
        vector<int>res(2,0);
		/**
		*先计算所有数的 异或  值
		* 这样便得到了只出现1次的两个数的异或值xors
		*/
        for(int i=1;i<nums.size();i++){
            xors^=nums[i];
        }
		/**
		*因为两个数不同,所以必然存在异或之后值为1的位
		*找到第一个值为1的位,
		*做与运算后,即只有那一位会为1
		* 1100   
		*-1100  ======> 0100
		*做与运算后得到  0100
		*/
        xors&=(-xors);
        /**
		*所有的数便可以分成两部分
		*一部分xors置1的那一位为1，一部分置1的那一位不为1
		*所以分批做异或运算
		*每一批中便转化成了每个数出现两次,有一个数出现一次的问题
		*/
        for(int i=0;i<nums.size();i++){
            if(nums[i]&xors){
                res[0]^=nums[i];
            }else{
                res[1]^=nums[i];
            }
        }
        return res;
    }
};