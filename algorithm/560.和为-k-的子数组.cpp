/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0;
        unordered_map<int,int> map;
        int sum=0;
        // map[nums[0]]=1;
        // int sum=nums[0];
        map[0]=1;
        for(int i=0;i<nums.size();i++) {
            sum+=nums[i];
            if(map.find(sum-k)!=map.end()) ans+=map[sum-k];
            map[sum]++; 
        }
        return ans;
    }
};
// @lc code=end

