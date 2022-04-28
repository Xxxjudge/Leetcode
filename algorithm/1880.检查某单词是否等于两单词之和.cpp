/*
 * @lc app=leetcode.cn id=1880 lang=cpp
 *
 * [1880] 检查某单词是否等于两单词之和
 */

// @lc code=start
class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int count=0;
        int first=0,second=0,target=0;
        for(auto c:firstWord) first=first*10+c-'a';
        for(auto c:secondWord) second=second*10+c-'a';
        for(auto c:targetWord) target=target*10+c-'a';
        if(first+second==target) return true;
        return false;
    }
};
// @lc code=end

