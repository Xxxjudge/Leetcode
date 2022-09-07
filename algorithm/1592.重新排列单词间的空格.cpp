/*
 * @lc app=leetcode.cn id=1592 lang=cpp
 *
 * [1592] 重新排列单词间的空格
 */

// @lc code=start
class Solution {
public:
    string reorderSpaces(string text) {
        vector<string> words;
        int num=0;
        for(auto ch:text) if(ch==' ') num++;
        char* tok;
        tok=strtok((char*)text.c_str()," ");
        while(tok!=NULL) {
            words.push_back(tok);
            tok=strtok(NULL," ");
        }
        if(words.size()<=1) {
            string s(num,' ');
            return words[0]+s;
        }
        int more=num%(words.size()-1);
        num/=words.size()-1;
        string spaceStr(num,' ');
        string tail(more,' ');
        string ans;
        for(auto s:words) ans+=s+spaceStr;
        ans=ans.substr(0,ans.size()-num);
        return ans+tail;
    }
};
// @lc code=end

