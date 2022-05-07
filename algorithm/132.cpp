class Solution {
public:
    bool isPartition(string s) {
        int n=s.size();
        if(n<=1) return true;
        int mid=n/2;
        if(n%2==0) {
            int left=mid-1,right=mid;
            while(left!=-1) {
                if(s[left]!=s[right]) return false;
                left--;
                right++;
            }
        } else {
            int left=mid-1,right=mid+1;
            while(left!=-1) {
                if(s[left]!=s[right]) return false;
                left--;
                right++;
            }
        }
        return true;
    }

    int minCut(string s) {
        int n=s.size();
        int ans=n;
        vector<vector<bool>> dp(n,vector<bool>(n+1,false));
        for(int i=0;i<n;i++) 
            for(int j=i+1;j<n+1;j++)
                if(isPartition(s.substr(i,j-i))) dp[i][j]=true;

        vector<int> minCount(n);
        minCount[0]=0;
        for(int i=1;i<n;i++) {
            minCount[i]=minCount[i-1]+1;
            if(dp[0][i+1]) {minCount[i]=0;continue;}
            for(int j=1;j<i;j++) {
                if(dp[j][i+1]) minCount[i]=min(minCount[i],minCount[j-1]+1);
            }
            // cout<<minCount[i]<<' ';
        }
        return minCount[n-1];
    }
};