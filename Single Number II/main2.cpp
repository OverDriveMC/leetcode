class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
		///每次判断第i位是否为1
        for(int i=0;i<32;i++){
            int sum=0;
            for(int j=0;j<nums.size();j++){
				///假如第j个数的第i位  与1做与运算得到1
                if( (nums[j]>>i )&1 ==1 ){
					///那么sum++
                    sum++;
					///sum对3取模
                    sum%=3;
                }
            }
			///因为每个数出现3次,假如没有多余的1说明sum%3会正好为0,否则说明该位置有多余的1,所以该位置1
            if(sum!=0){
                ans |= (1<<i);
            }
        }
        return ans;
    }
};