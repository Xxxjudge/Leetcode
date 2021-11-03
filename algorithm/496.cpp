class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(),-1);
        int tag=0;
        for(int i=0;i<nums1.size();i++) {
            for(int j=0;j<nums2.size();j++) {
                if(nums1[i]==nums2[j]) 
                tag=1;
                if(tag==1&&nums2[j]>nums1[i]) {
                    ans[i]=nums2[j];
                    tag=0;
                    break;
                }
                if(j==nums2.size()-1) tag=0;
            }
        }
        return ans;
    }
};