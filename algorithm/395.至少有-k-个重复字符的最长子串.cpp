/*
 * @lc app=leetcode.cn id=395 lang=cpp
 *
 * [395] 至少有 K 个重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int dfs(string& s,int l,int r,int k) {
        vector<int> cnt(26,0);
        for(int i=l;i<=r;i++) {
            cnt[s[i]-'a']++;
        }
        char split=0;
        for(int i=0;i<26;i++) {
            if(cnt[i]>0&&cnt[i]<k) split='a'+i;
        }
        if(split==0) return r-l+1;
        int i=l;
        int ans=0;
        while(i<=r) {
            while(i<=r&&s[i]==split) i++;
            int start=i;
            if(i>r) break;
            int length=0;
            while(i<=r&&s[i]!=split) i++;
            ans=max(ans, dfs(s,start,i-1,k));
        }
        return ans;
    }
    int longestSubstring(string s, int k) {
        int n=s.size();
        return dfs(s,0,n-1,k);
    }
};
// @lc code=end

