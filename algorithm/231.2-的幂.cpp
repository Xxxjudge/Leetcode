/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2 的幂
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfTwo(int n) {
        for(int i=0;i<31;i++) {
            int m=1<<i;
            if(m==n) return true;
        }
        return false;
    }
};
// @lc code=end

