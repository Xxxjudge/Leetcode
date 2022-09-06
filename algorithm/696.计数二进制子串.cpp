/*
 * @lc app=leetcode.cn id=696 lang=cpp
 *
 * [696] 计数二进制子串
 */

// @lc code=start
class Solution {
public:
    int countBinarySubstrings(string s) {
        int n=s.size();
        if(n<=1) return 0;
        int left=0,right=1,ans=0;
        for(int i=1;i<n;i++) {
            if(s[i]==s[i-1]) right++;
            else {
                ans+=min(left,right);
                left=right;
                right=1;
            }
        }
        ans+=min(left,right);
        return ans;
    }
};
// @lc code=end

