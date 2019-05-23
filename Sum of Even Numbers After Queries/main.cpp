/**
整数数组A, 查询数组queries
每个查询为一个二元集,对于第i个查询,定义：
	val=queries[i][0]
	index=queries[i][1]
将  val 与A[index]做加和, 返回A中的当前偶数的和。
Input: A = [1,2,3,4], queries = [[1,0],[-3,1],[-4,0],[2,3]]
Output: [8,6,2,4]
Explanation: 
At the beginning, the array is [1,2,3,4].
After adding 1 to A[0], the array is [2,2,3,4], and the sum of even values is 2 + 2 + 4 = 8.
After adding -3 to A[1], the array is [2,-1,3,4], and the sum of even values is 2 + 4 = 6.
After adding -4 to A[0], the array is [-2,-1,3,4], and the sum of even values is -2 + 4 = 2.
After adding 2 to A[3], the array is [-2,-1,3,6], and the sum of even values is -2 + 6 = 4.
数据集范围：
	1 <= A.length <= 10000
	-10000 <= A[i] <= 10000
	1 <= queries.length <= 10000
	-10000 <= queries[i][0] <= 10000
	0 <= queries[i][1] < A.length
*/
/**
思路：先计算当前数组中的偶数的和,
对于第i个查询,分别获取val,index
判断 A[index]是否为偶数,
假如为偶数,判断val
	val为偶数,和为偶数,直接将val添加进sum,
	val为奇数,和为奇数,所以从sum中去掉A[index]
假如为奇数,判断val
	val为奇数,和为偶数,将val与A[index]添加进sum
	val为偶数,和为奇数,不做操作
最后统一更新A[index]=A[index]+val
*/
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int>res;
        int cursum=sum(A);
		//记住用引用 会加快速度
        for(auto& query : queries){
            if(A[query[1]] % 2 ==0){
                if( query[0] %2 ==0  ){
                    cursum+= query[0];
                }else{
                    cursum-= A[query[1]] ;
                }
                A[query[1]] +=query[0];
            }else{
                 A[query[1]] +=query[0];
                if( query[0] %2 !=0  ){
                    cursum+=A[query[1]]  ;
                }
            }
           
            res.push_back(cursum);
        }
        return res;
    }
    int sum(vector<int>&A){
        int res=0;
        for(auto& i : A){
            if(i%2==0)
                res+=i;
        }
        return res;
    } 
};
/**
	输入输出加速
*/
static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL);return 0; }();