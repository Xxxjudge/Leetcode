class Solution {
public:
    void backtrack(vector<int>& nums,int n,int tempsum,int i,int S,int& ans) {
        if(n==i) {
            if(tempsum==S) ans++;
            return;
        } else {
            backtrack(nums,n,tempsum+nums[i],++i,S,ans);
            i--;
            backtrack(nums,n,tempsum-nums[i],++i,S,ans);
        }
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        int ans=0;
        int n=nums.size();
        int tempsum=0;
        backtrack(nums,n,tempsum,0,S,ans);

        return ans;
    }
};