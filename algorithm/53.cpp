class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre=nums[0],maxS=nums[0];
        for(int i=1;i<nums.size();i++) {
            pre=max(nums[i],pre+nums[i]);
            maxS=max(maxS,pre);
        }
        return maxS;
    }
};