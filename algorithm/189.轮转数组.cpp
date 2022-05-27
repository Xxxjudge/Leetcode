/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k>nums.size()) k=k%nums.size();
        vector<int> n1(nums.end()-k,nums.end());
        vector<int> n2(nums.begin(),nums.end()-k);
        n1.insert(n1.end(),n2.begin(),n2.end());
        nums.swap(n1);
    }
};
// @lc code=end

