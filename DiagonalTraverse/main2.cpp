#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int> >& matrix) {
        vector<int> res;
        if(matrix.size()==0){
            return res;
        }
        int M=matrix.size();
        int N=matrix[0].size();
        int r=0,c=0;
        for(int i=0;i<M*N;i++){
            cout<<r<<"  "<<c<<endl;
            res.push_back(matrix[r][c]);
           // cout<< ((r+c)&1) <<endl;
            if((r+c)%2 == 0 ){
                if(c==N-1){
                    r++;
                }else if(r==0){
                    c++;
                }else{
                    r--;
                    c++;
                }
            }else{
                if(r==M-1){
                    c++;
                }else if(c==0){
                    r++;
                }else{
                    r++;
                    c--;
                }
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

