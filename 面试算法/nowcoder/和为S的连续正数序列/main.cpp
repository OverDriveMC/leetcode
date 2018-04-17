/**
找出所有和为S的连续正数序列
*/

/**
假设有n个数,第一个数为a1
(a1+a1+n-1)n/2=sum   =====>a1= sum/n - (n-1)/2
满足条件的n分两种情况:
n为奇数时:序列中间的数正好是序列的平均值,所以条件为: (n&1)==1 && sum%n==0;
n为偶数时:序列中间的两个数的平均值是序列的平均值,并且这个平均值的小数部分为0.5
   sum% n==n/2  (sum/n= x+1/2   ====> sum=nx +n/2 ===>sum%n==n/2  ===> sum%n *2 ==n 偶数因为是*2)
   
又因为n>=2,为了让n尽可能大,序列从1开始
S=(1+n)*n/2, 得到n<sqrt(2S)
*/
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> >res;
        for(int n=sqrt(2*sum) ;n>=2;n--){
            if( ((n&1) && (sum%n==0)) || (sum%n*2==n)  ){
                vector<int>tmp;
                for(int i=0 , j= sum/n -(n-1)/2; i<n;i++){
                    tmp.push_back(j);
                    j++;
                }
                res.push_back(tmp);
            }
        }
        return res;
    }
};