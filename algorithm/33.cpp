class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0) return -1;
        int left=0,right=nums.size()-1,mid=(left+right)/2;
        while(left<=right) {
            if(target==nums[mid]) return mid;
            else if(nums[left]<=nums[mid]) {
                if(target>=nums[left]&&target<nums[mid]) {
                    right=mid-1;
                    mid=(left+right)/2;
                } else {
                    left=mid+1;
                    mid=(left+right)/2;
                }
            } else if(nums[right]>=nums[mid]) {
                if(target>nums[mid]&&target<=nums[right]) {
                    left=mid+1;
                    mid=(left+right)/2;
                } else {
                    right=mid-1;
                    mid=(left+right)/2;
                }
            }
        }
        return -1;
    }
};