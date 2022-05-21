/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 */

// @lc code=start
class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans=0;
        for(auto x:s) ans^=x;
        for(auto x:t) ans^=x;
        return ans;
    }
};
// @lc code=end

