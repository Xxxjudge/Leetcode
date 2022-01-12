class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++) { 
            if(nums[i]<=0) nums[i]=n+1;
        }
        for(int i=0;i<n;i++) {
            int num=abs(nums[i]);
            if(num<=n) {
                nums[num-1]=-abs(nums[num-1]);
            }
        }
        for(int i=0;i<n;i++) {
            if(nums[i]>0) return i+1;
        }
        return n+1;
    }
};//将小于0的变成n+1，然后将有的数的位置的数变为负数，最后找到那个正数取下标+1