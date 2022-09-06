/*
 * @lc app=leetcode.cn id=693 lang=cpp
 *
 * [693] 交替位二进制数
 */

// @lc code=start
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int last=n&1;
        n>>=1;
        while(n!=0){
            if((1&n)==last) return false;
            last=n&1;
            n>>=1;   
        }
        return true;
    }
};
// @lc code=end

