/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 */

// @lc code=start
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> mymap;
        vector<string> ans;
        if(s.size()<=10) return ans;
        for(int i=0;i<=s.size()-10;i++) {
            string temp=s.substr(i,10);
            mymap[temp]++;
            if(mymap[temp]==2) ans.push_back(temp);
        }
        return ans;
    }
};
// @lc code=end

