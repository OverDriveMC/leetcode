class Solution {
    public int maximalSquare(char[][] matrix) {
        if(matrix.length==0 || matrix[0].length==0){
            return 0;
        }        
        int m=matrix.length;
        int n=matrix[0].length;
        int maxn=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1'){
                    int curlen=1;
                    boolean flag=true;
					/**
					计算以curlen为边长(i,j)为左上角顶点的正方形内是否全是1
					*/
                    while(flag && (i+curlen<m) && (j+curlen<n) ){
						//固定x轴查看y方向
                        for(int k=0;k<=curlen  &&(j+k <n )  ;k++){
                            if(matrix[i+curlen][j+k]!='1'){
                                flag=false;
                                break;
                            }
                        }   
						//固定y方向查看x轴
                        for(int k=0;k<=curlen && (i+k<m)  ;k++ ){
                            if(matrix[i+k][j+curlen]!='1'){
                                flag=false;
                                break;
                            }
                        }
						//假如flag依旧为true,说明正方形内都是1
                        if(flag){
                            curlen++;
                        }
                    }
                    maxn=Math.max(curlen,maxn);
                }
                
            }
        }
        return maxn*maxn;
    }
}