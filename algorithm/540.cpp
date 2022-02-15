class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int left=0,right=n-1;
        int mid=n/2;
        while(left!=right) {
            if(nums[mid]==nums[mid-1]) {
                if((right-left)/2%2==1) {
                    left=mid+1;
                    mid=(left+right)/2;
                } else {
                    right=mid-2;
                    mid=(left+right)/2;
                }
            } else if(nums[mid]==nums[mid+1]) {
                if((right-left)/2%2==1) {
                    right=mid-1;
                    mid=(left+right)/2;
                } else {
                    left=mid+2;
                    mid=(left+right)/2;
                }
            } else return nums[mid];
        }
        return nums[left];
    }
};