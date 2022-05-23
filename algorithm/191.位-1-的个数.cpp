/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
class Solution {
public:
    int bitnum(uint32_t n) {
        if(n==0) return 0;
        return bitnum(n/2)+n%2;
    }
    int hammingWeight(uint32_t n) {
        return bitnum(n);
    }
};
// @lc code=end

