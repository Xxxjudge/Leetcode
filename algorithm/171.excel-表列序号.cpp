/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel 表列序号
 */

// @lc code=start
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans=0;
        for(auto x:columnTitle) {
            ans=(x-'A'+1)+ans*26;
        }
        return ans;
    }
};
// @lc code=end

