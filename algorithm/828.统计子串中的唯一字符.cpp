/*
 * @lc app=leetcode.cn id=828 lang=cpp
 *
 * [828] 统计子串中的唯一字符
 */

// @lc code=start
class Solution {
public:
    int uniqueLetterString(string s) {
        // int n=s.size();
        // unordered_map<char,vector<int>> map;
        // int res=0;
        // for(int i=0;i<n;i++) map[s[i]].push_back(i);
        // for(auto it=map.begin();it!=map.end();it++) {
        //     int head=-1,tail;
        //     vector<int> item=it->second;
        //     for(int i=0;i<item.size();i++) {
        //         tail=(i<item.size()-1)?item[i+1]:n;
        //         res+=(item[i]-head)*(tail-item[i]);
        //         head=item[i];
        //     }
        // }
        // return res;
        vector<int> pre(26,-1);
        vector<int> now(26,-1);
        int n=s.size();
        int ans=0;
        for(int i=0;i<s.size();i++) {
            int index=s[i]-'A';
            if(now[index]!=-1) {
                ans+=(now[index]-pre[index])*(i-now[index]);
            }
            pre[index]=now[index];
            now[index]=i;
        }
        for(int i=0;i<26;i++) {
            if(now[i]!=-1) ans+=(now[i]-pre[i])*(n-now[i]);
        }
        return ans;
    }
};
// @lc code=end

