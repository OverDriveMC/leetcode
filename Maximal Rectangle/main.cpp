#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.empty()){
            return 0;
        }
        int row=matrix.size();
        int column=matrix[0].size();

        int left[column],right[column],height[column];
        memset(left,0,sizeof(left));
        memset(right,0x3f3f3f3f,sizeof(right));
        memset(height,0,sizeof(height));

        int maxA=0;
        for(int i=0;i<row;i++){
            int cur_left=-1;
            for(int j=0;j<column;j++){
                if(matrix[i][j]=='1'){
                    height[j]++;
                    if(cur_left==-1){
                        cur_left=j;
                    }
                    left[j]=max(left[j],cur_left);
                }else{
                    height[j]=0;
                    left[j]=0;
                    cur_left=-1;
                }


            }

            int cur_right=-1;
            for(int j=column-1;j>=0;j--){
                if(matrix[i][j]=='1'){
                    if(cur_right==-1){
                        cur_right=j+1;
                    }
                    right[j]=min(right[j],cur_right);
                }else{
                    right[j]=column;
                    cur_right=-1;
                }
            }

            for(int j=0;j<column;j++){
                maxA=max(maxA, (right[j]-left[j])*height[j]);
            }

        }
        return maxA;
    }
};

void test1(){
    Solution s;
    vector<vector<char> > matrix;
    string s1="0001000";
    string s2="0100100";
    string s3="0111100";
    vector<char>v1;
    for(int i=0;i<s1.size();i++){
        v1.push_back(s1[i]);
    }
    matrix.push_back(v1);


    vector<char>v2;
    for(int i=0;i<s2.size();i++){
        v2.push_back(s2[i]);
    }
    matrix.push_back(v2);

    vector<char>v3;
    for(int i=0;i<s3.size();i++){
        v3.push_back(s3[i]);
    }
    matrix.push_back(v3);

    cout<<s.maximalRectangle(matrix)<<endl;
}

void test2(){
    Solution s;
    vector<vector<char> > matrix;
    string s1="10100";
    string s2="10111";
    string s3="11111";
    string s4="10010";
    vector<char>v1;
    for(int i=0;i<s1.size();i++){
        v1.push_back(s1[i]);
    }
    matrix.push_back(v1);


    vector<char>v2;
    for(int i=0;i<s2.size();i++){
        v2.push_back(s2[i]);
    }
    matrix.push_back(v2);

    vector<char>v3;
    for(int i=0;i<s3.size();i++){
        v3.push_back(s3[i]);
    }
    matrix.push_back(v3);
    vector<char>v4;
    for(int i=0;i<s4.size();i++){
        v4.push_back(s4[i]);
    }
    matrix.push_back(v4);

    cout<<s.maximalRectangle(matrix)<<endl;
}

int main(){
    test1();
    test2();
}
