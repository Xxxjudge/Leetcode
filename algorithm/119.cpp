class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex<0) return {};
        if(rowIndex==0) return {1};
        vector<int> ans;
        for(int i=0;i<rowIndex+1;i++) ans.push_back(CNK(rowIndex,i));
        return ans;
    }
    long CNK(int n,int k) {
        if(k==0) return 1;
        long ans=1;
        for(int i=0;i<k;i++) ans=ans*(n-i)/(i+1);    
        return ans;
    }
};