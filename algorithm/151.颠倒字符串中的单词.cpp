/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 颠倒字符串中的单词
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        stack<string> temp;
        char* tok;
        tok=strtok((char*)s.c_str()," ");
        if(tok==NULL) return "";
        while(tok!=NULL) {
            temp.push(tok);
            tok=strtok(NULL," ");
        }
        string ans=temp.top();
        temp.pop();
        while(!temp.empty()) {
            ans+=' '+temp.top();
            temp.pop();
        }
        return ans;
    }
};
// @lc code=end

