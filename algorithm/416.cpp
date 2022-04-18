class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto x:nums) {
            sum+=x;
        }
        int target=sum/2;
        if(sum%2==1) return false;
        if(n<=1) return false;
        vector<vector<bool>> dp(n,vector<bool>(target+1,false));
        if(nums[0]<=target) dp[0][nums[0]]=true;
        else return false;
        dp[0][nums[0]]=true;
        for(int i=1;i<n;i++) {
            for(int j=0;j<target+1;j++) {
                dp[i][j]=dp[i-1][j];
                if(j==nums[i]) {
                    dp[i][j]=true;
                    continue;
                }
                if(nums[i]<j) {
                    dp[i][j]=dp[i-1][j]||dp[i-1][j-nums[i]];
                }

            }
        }

        return dp[n-1][target];

    }
};