class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int>res;
        if(matrix.size()==0 || matrix[0].size()==0){
            return res;
        }
        int margin=0;
        int m=matrix.size();
        int n=matrix[0].size();
        unsigned long number=m*n;
        int i,j;
        while(res.size() < number){
            i=margin;
            j=margin;
            while( (res.size() <number) &&  j<(n-margin)){
                res.push_back(matrix[i][j++]);
            }
			///注意还要在减回来,每次都要去判断一下是否元素数量是否已经加完
            j--;
            i++;
            while( (res.size() <number) && i<(m-margin)){
                res.push_back(matrix[i++][j]);
            }
            i--;
            j--;
            while( (res.size() <number) && j>=margin){
                res.push_back(matrix[i][j--]);
            }
            j++;
            i--;
            while( (res.size() <number) && i>margin){
                res.push_back(matrix[i--][j]);
            }
            margin++;
        }
        return res;
    }
};