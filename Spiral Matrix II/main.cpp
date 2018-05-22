/**
Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
按照spiral order方式生成1-n^2的矩阵
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int dirs[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
        int cnt=n*n;
        int cur=1;
        vector<vector<int>>res(n, vector<int>(n,0));
		//一开始的坐标
        int x=0,y=-1;
        int d=0;
		//m:纵向元素个数,n:横向元素个数
		//每次加完之后,该方向的元素下次添加的个数变会少一个
        int m=n-1;
        while(cur<=cnt){
            for(int i=0;i<n;i++){
                x+=dirs[d][0];
                y+=dirs[d][1];
                res[x][y]=cur;
                cur++;
            }
            n--;
            swap(m,n);
            d=(d+1)%4;
        }
        return res;
    }
};