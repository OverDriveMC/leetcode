class Solution {
public:
    int jumpFloor(int number) {
        if(number<=1){
            return 1;
        }else if(number==2){
            return 2;
        }
        vector<vector<int>> matrix(2, vector<int>(2,0));
        matrix[0][0]=1;
        matrix[0][1]=1;
        matrix[1][0]=1;
		/**
		*矩阵n次方的第[0][0]元素
		*/
        return quickPow(matrix,number)[0][0];
    }
private:
    vector<vector<int>> quickPow(vector<vector<int>>&matrix ,int n){
        vector<vector<int>>res(2, vector<int>(2,0));
        res[0][0]=1;
        res[0][1]=0;
        res[1][0]=0;
        res[1][1]=1;
        while(n){
            if(n&1){
                res=multiply(res,matrix);
            }
            matrix=multiply(matrix,matrix);
            n>>=1;
        }
        return res;
    }
    vector<vector<int>>multiply(vector<vector<int>>& a, vector<vector<int>> &b){
        vector<vector<int>>res(2, vector<int>(2,0));
        res[0][0]=a[0][0]*b[0][0]+a[0][1]*b[1][0];
        res[0][1]=a[0][0]*b[0][1]+a[0][1]*b[1][1];
        res[1][0]=a[1][0]*b[0][0]+a[1][1]*b[1][0];
        res[1][1]=a[1][0]*b[0][1]+a[1][1]*b[1][1];
        
        return res; 
    }
};