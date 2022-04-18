class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        int rowNum=intervals.size();
        for(int i=0;i<rowNum;i++) {
            int left=intervals[i][0];
            int right=intervals[i][1];
            while(i<(rowNum-1)&&right>=intervals[i+1][0]) {
                right=max(intervals[i+1][1],right);
                i++;
            }
            vector<int> temp{left,right};
            ans.push_back(temp);
        }
        if(ans[ans.size()-1][1]<intervals[rowNum-1][0]) ans.push_back(intervals[rowNum-1]);
        return ans;
    }
};