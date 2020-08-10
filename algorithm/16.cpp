class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int twosum=0;
        int error=abs(nums[0]+nums[1]+nums[2]-target);
        int ans=nums[0]+nums[1]+nums[2];
        for(int i=0;i<n-2;i++) {
            twosum=twoSumClosest(nums,i+1,n-1,target-nums[i]);
            ans=error>abs(twosum+nums[i]-target)?(twosum+nums[i]):ans;
            error=abs(ans-target);
        }
        return ans;
    }
    int twoSumClosest(vector<int>& nums,int front,int end,int target) {
        int a=nums[front];
        int b=nums[end];
        int ans=a+b;
        int error=abs(ans-target);
        while(front<end-1) {
            if(a+b>target) {
                end-=1;
                b=nums[end];
                ans=error>abs(a+b-target)?(a+b):ans;
                error=abs(ans-target);
            }
            if(a+b<target) {
                front+=1;
                a=nums[front];
                ans=error>abs(a+b-target)?(a+b):ans;
                error=abs(ans-target);
            }
            if(a+b==target) return target;
        }
        return ans;
    }
};