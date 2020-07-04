class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> occ;
        int i=0,n=s.size(),rk=-1,ans=0;
        for(i=0;i<n;i++)//i为左边位置，rk为右边位置，相减加一为最长子串
        {
            if(i>0)
            occ.erase(s[i-1]);
            while(rk<n-1&&!occ.count(s[rk+1]))
            {
                occ.insert(s[rk+1]);
                rk++;
            }
            if(rk-i+1>ans)
            ans=rk+1-i;
        }
        return ans;
    }
};