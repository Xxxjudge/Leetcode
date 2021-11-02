class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reachposition=0;
        for(int i=0;i<nums.size();i++) {
            if(i>reachposition) return false;
            reachposition=max(reachposition,i+nums[i]);
        }
        return true;
    }
};