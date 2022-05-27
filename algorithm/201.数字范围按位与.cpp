/*
 * @lc app=leetcode.cn id=201 lang=cpp
 *
 * [201] 数字范围按位与
 */

// @lc code=start
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int m=1<<30;
        int ans=0;
        while(m!=0) {
            if((left&m)==(right&m)) ans|=left&m;
            else return ans;
            m=m>>1;
        }
        return ans;
    }
};
// @lc code=end

