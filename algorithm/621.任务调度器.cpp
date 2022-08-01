/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] 任务调度器
 */

// @lc code=start
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> map;
        int length=tasks.size();
        for(auto x:tasks) map[x]++;
        int max=0;
        for(auto it=map.begin();it!=map.end();it++) {
            max=max>(it->second)?max:(it->second);
        }
        int num=0;
        for(auto it=map.begin();it!=map.end();it++) {
            if(it->second==max) num++;
        }
        int ans1=(max-1)*(n+1)+num;
        int ans2=length;
        return ans1>ans2?ans1:ans2;
    }
};
// @lc code=end

