/*
 * @lc app=leetcode.cn id=371 lang=cpp
 *
 * [371] 两整数之和
 */

// @lc code=start
class Solution {
public:
    int getSum(int a, int b) {
        unsigned int carry=0;
        while(b!=0) {
            carry=(unsigned int)(a&b)<<1;
            a=a^b;
            b=carry;
        }
        return a;
    }
};
// @lc code=end

