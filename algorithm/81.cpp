class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for(auto x:nums) {
            if(x==target) return true;
        }
        return false;
    }
};
//无脑遍历也是99，没有必要用二分搜索