/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        stack<char> cstack;
        stack<int> nums;
        string ans="";
        int i=0;
        while(i<s.size()) {
            if(cstack.empty()&&s[i]>='a'&&s[i]<='z') {
                ans+=s[i];
                i++;
            } else if(s[i]>='0'&&s[i]<='9') {
                string temp="";
                while(s[i]>='0'&&s[i]<='9') {
                    temp+=s[i];
                    i++;
                }
                nums.push(stoi(temp));
                cout<<nums.top()<<' ';
            } else if(s[i]!=']') {
                cstack.push(s[i]);
                i++;
            } else {
                string subs="";
                while(cstack.top()!='[') {
                    subs=cstack.top()+subs;
                    cstack.pop();
                }
                cstack.pop();
                cout<<subs<<' ';
                int n=nums.top();
                nums.pop();
                for(int i=0;i<n;i++) {
                    for(int j=0;j<subs.size();j++) 
                        cstack.push(subs[j]);
                }
                i++;
            }
        }
        string temp="";
        while(!cstack.empty()) {
            temp=cstack.top()+temp;
            cstack.pop();
        }
        return ans+temp;
    }
};
// @lc code=end

