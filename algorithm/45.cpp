class Solution {
public:
    int jump(vector<int>& nums) {
        int ans=0,maxlength=0,tempmaxlength=0;
        for(int i=0;i<nums.size()-1;i++) {
            maxlength=max(maxlength,i+nums[i]);
            if(tempmaxlength==i) {
                tempmaxlength=maxlength;
                ans++;
            }
        }
        return ans;
    }
};