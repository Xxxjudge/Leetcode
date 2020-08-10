class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=0,res=0;
        for(int i=0;i<32;i++) {
            sum=0;
            for(int j=0;j<n;j++) {
                sum+=(nums[j]>>i)&1;
            }
            res+=(sum%3)<<i;
        }
        return res;
    }
};
//位运算考察