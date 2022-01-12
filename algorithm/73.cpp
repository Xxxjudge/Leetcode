class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> row(matrix.size());
        vector<int> col(matrix[0].size());
        for(int m=0;m<matrix.size();m++) 
            for(int n=0;n<matrix[0].size();n++) {
                if(matrix[m][n]==0) {
                    row[m]=1;
                    col[n]=1;
                }
            }
        
        for(int m=0;m<matrix.size();m++) 
            for(int n=0;n<matrix[0].size();n++) {
                if(row[m]==1||col[n]==1) matrix[m][n]=0;
            }
        
    }
};//取行列数做标记，o(mn)时间复杂度就可以