#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vec;
typedef vector<vec > mat;

class Solution {
public:

    mat mul(mat&a,mat &b){
/**
	每一维是一个b[0].size()的vector
*/		
        mat c(a.size() , vec(b[0].size()));
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++){
                    c[i][j]+=a[i][k]*b[k][j];
                }
            }
        }
        return c;
    }
/**
	定义以及返回二维指针的方式
    int** quickpower(int a[2][2],int n){
        int **res=new int*[2];
        res[0]=new int[2];
        res[1]=new int[2];
        return res;
    }
**/


    int climbStairs(int n) {

        mat a(2,vec(2));
        a[0][0]=1;
        a[0][1]=1;
        a[1][0]=1;
        a[1][1]=0;

        mat res(a.size(),vec(a.size()));
        for(int i=0;i<a.size();i++){
            res[i][i]=1;
        }
        while(n){
            if(n&1) res=mul(res,a);
            a=mul(a,a);
            n>>=1;
        }

        return res[0][0];
    }
};


int main(){

    Solution s;
    for(int i=1;i<=10;i++){
        cout<<i<<"  "<<s.climbStairs(i)<<endl;
    }
    return 0;
}
