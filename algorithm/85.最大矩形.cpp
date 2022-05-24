/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

// @lc code=start
class Solution {
public:
    int maxR(vector<int>& height) {
        int n=height.size();
        int ans=0;
        vector<int> left(n),right(n,n);
        left[0]=-1;
        for(int i=1;i<n;i++) {
            int t=i-1;
            while(t>=0&&height[t]>=height[i]) t=left[t];
            left[i]=t;
        }
        for(int i=n-2;i>=0;i--) {
            int t=i+1;
            while(t<n&&height[t]>=height[i]) t=right[t];
            right[i]=t;
        }
        for(int i=0;i<n;i++) {
            ans=max(ans,(right[i]-left[i]-1)*height[i]);
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0) return 0;
        int ans=0;
        vector<int> height(matrix[0].size(),0);
        for(int i=0;i<matrix.size();i++) {
            for(int j=0;j<matrix[0].size();j++) {
                if(matrix[i][j]=='0') height[j]=0;
                else height[j]+=1;
            }
            ans=max(ans,maxR(height));
        }
        return ans;
    }
};
// @lc code=end

