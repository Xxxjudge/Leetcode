class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()||matrix[0].empty()) return false;
        int i=0,j=0;
        int m=matrix.size(),n=matrix[0].size();
        if(matrix[0][0]>target||matrix[m-1][n-1]<target) return false;
        while(i<m) {
            if(matrix[i][0]<target&&i!=m-1) i++;
            if(matrix[i][0]==target) return true;
            if(matrix[i][0]>target) {i--;break;}
            if(i==m-1) break;  
        }
        while(j<n) {
        if(matrix[i][j]<target&&j!=n-1) j++;
        if(matrix[i][j]==target) return true;
        if(matrix[i][j]>target||j==n-1) return false;
        }
        return false;
    }
};