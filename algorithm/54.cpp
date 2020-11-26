class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        if(m==0||n==0) return {};
        vector<int> ans;
        int left=0,right=n-1,top=0,bottom=m-1;
        while(true) {
            for(int i=left;i<=right;i++) ans.push_back(matrix[top][i]);
            top++;
            if(top>bottom) break;
            for(int i=top;i<=bottom;i++) ans.push_back(matrix[i][right]);
            right--;
            if(right<left) break;
            for(int i=right;i>=left;i--) ans.push_back(matrix[bottom][i]);
            bottom--;
            if(top>bottom) break;
            for(int i=bottom;i>=top;i--) ans.push_back(matrix[i][left]);
            left++;
            if(right<left) break;
        }
        return ans;
    }
};