class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()<3)  return ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2&&nums[i]<=0;i++) {
            if(i>0&&nums[i]==nums[i-1]) continue;
            int target=-nums[i];
            int start=i+1;
            int end=nums.size()-1;
            vector<int> temp;
            while(start<end) {
                if(nums[start]+nums[end]<target) start++;
                else if(nums[start]+nums[end]>target) end--;
                else if(nums[start]+nums[end]==target) {
                    temp={nums[i],nums[start],nums[end]};
                    ans.push_back(temp);
                    temp.clear();
                    start++;
                    end--;
                    while(start<end&&nums[start]==nums[start-1]&&nums[end]==nums[end+1]) {
                        start++;
                        end--;
                    }
                }
            }
        }
        return ans;
    }
};//双指针加单层循环实现，没问题！