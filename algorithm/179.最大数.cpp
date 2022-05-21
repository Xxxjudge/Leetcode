/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start
class Solution {
public:
    bool static mycompare(string a,string b) {
        string left=a+b;
        string right=b+a;
        return left>right;
    }
    string largestNumber(vector<int>& nums) {
        string ans;
        vector<string> arr;
        for(auto x:nums) {
            arr.push_back(to_string(x));
        }
        sort(arr.begin(),arr.end(),mycompare);
        for(auto x:arr) ans+=x;
        if(ans[0]=='0') return "0";
        return ans;
    }
};
// @lc code=end

