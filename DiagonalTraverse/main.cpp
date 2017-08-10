#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int> >& matrix) {
        vector<int>res;
        if(matrix.size()==0){
            return res;
        }
        int M=matrix.size();
        int N=matrix[0].size();
        int i=0,j=0;
        res.push_back(matrix[i][j]);
        while(i<M && j<N){
            ///先往上走
            while(i-1>=0 && j+1<N ){
                --i;
                ++j;
                res.push_back(matrix[i][j]);
            }
            ///不需要管i的位置,只用根据j的位置即可更新
            if(j<N){
                j++;
            }else{
                i++;
            }
            //cout<<i<<"  "<<j<<endl;
            if(i>=0 && i<M && j>=0 && j<N){
                res.push_back(matrix[i][j]);
            }
            ///再往下走
            while(i+1 <M && j-1 >=0){
                i++;
                j--;
                res.push_back(matrix[i][j]);
            }
            if(i+1<M){
                i++;
            }else{
                j++;
            }
            if(i>=0 && i<M && j>=0 && j<N){
                res.push_back(matrix[i][j]);
            }
        }
        return res;
    }
};


int main(){
    vector<vector<int> > matrix;
    vector<int>vec1;
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);
    matrix.push_back(vec1);
    vector<int>vec2;
    vec2.push_back(4);
    vec2.push_back(5);
    vec2.push_back(6);
    matrix.push_back(vec2);
    vector<int>vec3;
    vec3.push_back(7);
    vec3.push_back(8);
    vec3.push_back(9);
    matrix.push_back(vec3);

    Solution s;
    vector<int>res=s.findDiagonalOrder(matrix);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;

}
