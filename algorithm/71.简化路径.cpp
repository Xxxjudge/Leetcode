/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        char *tok;
        stack<string> mystack;
        tok=strtok((char *)path.c_str(),"/");
        while(tok!=NULL) {
            string temp=tok;
            if(temp=="..") {
                if(!mystack.empty()) mystack.pop();
            } else if(temp!=".") mystack.push("/"+temp);
            tok=strtok(NULL,"/");
        }
        string ans="";
        if(mystack.empty()) return "/";
        while(!mystack.empty()) {
            ans=mystack.top()+ans;
            mystack.pop();
        }
        return ans;
    }
};
// @lc code=end

