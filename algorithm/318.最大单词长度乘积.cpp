/*
 * @lc app=leetcode.cn id=318 lang=cpp
 *
 * [318] 最大单词长度乘积
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size();
        int ans=0;
        vector<int> m(n,0);
        for(int i=0;i<n;i++) {
            string word=words[i];
            for(auto x:word) {
                if((m[i]&(1<<(x-'a')))==0) m[i]+=1<<(x-'a');
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                if((m[i]&m[j])==0) {
                    ans=ans>words[i].size()*words[j].size()?ans:words[i].size()*words[j].size();
                } 
            }
        }
        return ans;
    }
};
// @lc code=end

