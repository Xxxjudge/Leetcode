class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1;
        if(nums.size()==0) return 0;
        if(nums.size()<=2) return nums.size();
        for(int j=2;j<nums.size();j++) {
            if(nums[j]!=nums[i]||nums[j]!=nums[i-1]) {
                nums[i+1]=nums[j];
                i++;
            }
        }
        return i+1;
    }
};