/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int slength=s.size();
        if(slength<1) return true;
        int rlength=t.size();
        int r=0;
        for(int i=0;i<slength;i++) {
            while(r<rlength&&s[i]!=t[r]) r++;
            if(i==(slength-1)&&r<rlength) return true;
            r++;
        }
        return false;
    }
};
// @lc code=end

