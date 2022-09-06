/*
 * @lc app=leetcode.cn id=697 lang=cpp
 *
 * [697] 数组的度
 */

// @lc code=start
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,vector<int>> map;
        int degree=0;
        int ans=nums.size();
        for(int i=0;i<nums.size();i++) {
            map[nums[i]].push_back(i);
            int temp=map[nums[i]].size();
            degree=max(temp,degree);
        }
        for(auto it=map.begin();it!=map.end();it++) {
            if(it->second.size()==degree) {
                vector<int> temp=it->second;
                ans=min(ans,temp[temp.size()-1]-temp[0]+1);
            }
        }
        return ans;
    }
};
// @lc code=end

