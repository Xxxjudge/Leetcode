class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) return n;
        sort(nums.begin(),nums.end());
        int ans=0,length=1;
        for(int i=0;i<n-1;i++) {
            if(nums[i]==nums[i+1]) continue;
            if(nums[i]==nums[i+1]-1) length++;
            else{
                ans=max(length,ans);
                length=1;
            }
        }
        for(int i=0;i<n-1;i++) {
            if(nums[i]==nums[i+1]) continue;
            if(nums[i]==nums[i+1]+1) length++;
            else{
                ans=max(length,ans);
                length=1;
            }
        }
        ans=max(length,ans);
        return ans;
    }
};//偷懒做法，使用了排序所以未达到o(n)