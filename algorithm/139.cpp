class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        int wordNum=wordDict.size();
        vector<bool> dp(n,false);
        int minWord=wordDict[0].size();
        for(int i=0;i<wordNum;i++) {
            if(s.substr(0,wordDict[i].size())==wordDict[i]) dp[wordDict[i].size()-1]=true;
            minWord=wordDict[i].size()>minWord?minWord:wordDict[i].size();
        }
        for(int i=minWord-1;i<n;i++) {
            for(int j=0;j<wordNum;j++) {
                if(dp[i]==true) {
                    if(i+wordDict[j].size()<n&&s.substr(i+1,wordDict[j].size())==wordDict[j]) dp[wordDict[j].size()+i]=true;
                }

            }
        }
        return dp[n-1];

    }
};