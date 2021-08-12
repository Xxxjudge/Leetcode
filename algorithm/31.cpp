class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) return;
        int first,second;//寻找一个最右侧的升降数组，单独处理
        for(int i=n-1;i>0;i--) {
            if(nums[i]>nums[i-1]) {
                first=i-1;
                second=i;
                for(int j=n-1;j>second;j--) {
                    if(nums[j]>nums[first]) {
                        int t=nums[j];
                        nums[j]=nums[first];
                        nums[first]=t;
                        sort(nums.begin()+second,nums.end());
                        return;
                    }
                }
                swap(nums[first],nums[second]);
                sort(nums.begin()+second,nums.end());
                return;
            }
        }
        sort(nums.begin(),nums.end());
        return;
    }
};