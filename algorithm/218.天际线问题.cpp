/*
 * @lc app=leetcode.cn id=218 lang=cpp
 *
 * [218] 天际线问题
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {        
        int n=buildings.size();
        vector<vector<int>> ans;
        priority_queue<pair<int,int>> maxHeap;//保存高度及右点
        int i=0;
        int curHeight,curX;
        while(i<n||!maxHeap.empty()) {
            if(maxHeap.empty()||(i<n&&buildings[i][0]<=maxHeap.top().second)) {
                curX=buildings[i][0];
                while (i<n&&buildings[i][0]==curX) {
                    maxHeap.emplace(buildings[i][2],buildings[i][1]);
                    i++;
                }
            } else {
                curX=maxHeap.top().second;
                while(!maxHeap.empty()&&curX>=maxHeap.top().second) {
                    maxHeap.pop();
                }

            }
            curHeight=(maxHeap.empty())?0:maxHeap.top().first;
            if(ans.empty()||ans.back()[1]!=curHeight)
                ans.push_back({curX,curHeight});
            
        }
        return ans;



    }
};
// @lc code=end

