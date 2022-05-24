/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans=0;
        int n=heights.size();
        vector<int> left(n),right(n,n);
        left[0]=-1;
        for(int i=1;i<n;i++) {
            int t=i-1;
            while(t>=0&&heights[t]>=heights[i]) t=left[t];
            left[i]=t;
        }
        for(int i=n-2;i>=0;i--) {
            int t=i+1;
            while(t<n&&heights[t]>=heights[i]) t=right[t];
            right[i]=t;
        }
        for(int i=0;i<n;i++) {
            ans=max(ans,heights[i]*(right[i]-left[i]-1));
        }
        return ans;
    }
};
// @lc code=end

