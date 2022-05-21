/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 */

// @lc code=start
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans="";
        while(columnNumber>0) {
            char a0=(columnNumber-1)%26;
            ans+=a0+'A';
            columnNumber=(columnNumber-a0)/26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
// @lc code=end

