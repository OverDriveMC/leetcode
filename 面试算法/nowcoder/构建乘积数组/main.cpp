/**
给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。
*/
/*
先用连乘计算下三角,即先算出B[i]中的一部分,然后倒过来按上三角中的分布规律,把另一部分也乘进去
*/
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        if(A.size()==0){
            return vector<int>();
        }
        vector<int>B(A.size(),1);
		//计算下三角连乘
        for(int i=1;i<A.size();i++){
            B[i] *= B[i-1] * A[i-1];
        }
		//计算上三角连乘
        int temp=1;
        for(int i=A.size()-2;i>=0;i--){
            B[i]*=temp*A[i+1];
            temp*=A[i+1];
        }
        return B;
    }
};