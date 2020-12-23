class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.size()<4)  return ans;
        sort(nums.begin(),nums.end());
        for(int j=0;j<nums.size()-3;j++) {
            if(j>0&&nums[j]==nums[j-1]) continue;
            for(int i=j+1;i<nums.size()-2;i++) {
                if(i>j+1&&nums[i]==nums[i-1]) continue;
                int tempTarget=target-nums[i]-nums[j];
                int start=i+1;
                int end=nums.size()-1;
                vector<int> temp;
                while(start<end) {
                    if(nums[start]+nums[end]<tempTarget) start++;
                    else if(nums[start]+nums[end]>tempTarget) end--;
                    else if(nums[start]+nums[end]==tempTarget) {
                        temp={nums[j],nums[i],nums[start],nums[end]};
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
        }
        return ans;
    }
};//从三数之和到四数之和，加一层循环，然后注意限制重复条件！