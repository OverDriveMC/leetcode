class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int>res;
        if(matrix.size()==0 || matrix[0].size()==0){
            return res;
        }
        int m=matrix.size();
        int n=matrix[0].size();
		//第一维直接赋值即可
        res=matrix[0];
        int cnt=n*(m-1);
		///定义方向
        int dirs[4][2]={{1,0},{0,-1},{-1,0},{0,1}};
        int x=0,y=n-1,d=0;
        while(cnt){
            for(int i=1;i<m;i++){
                x+=dirs[d][0];
                y+=dirs[d][1];
                res.push_back(matrix[x][y]);
                cnt--;
            }
			///每次要加的长度减1
            m--;
            swap(m,n);
            d=(d+1)%4;
        }
        return res;
        
    }
};