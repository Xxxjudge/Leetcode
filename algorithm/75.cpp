class Solution {
public:
    void sortColors(vector<int>& nums) {
        int temp=0;
        for(int j=nums.size()-1;j>0;j--)
        for(int i=0;i<j;i++) {
            if(nums[i]>nums[i+1]) {
                temp=nums[i];
                nums[i]=nums[i+1];
                nums[i+1]=temp;
            }
        }
    }
};
//冒泡排序