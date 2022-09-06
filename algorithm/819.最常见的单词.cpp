/*
 * @lc app=leetcode.cn id=819 lang=cpp
 *
 * [819] 最常见的单词
 */

// @lc code=start
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        int most=0;
        unordered_map<string,int> map;
        string temp;
        for(int i=0;i<paragraph.size()+1;i++) {
            if(!isalpha(paragraph[i])||i==paragraph.size()) {
                if(!temp.empty()&&find(banned.begin(),banned.end(),temp)==banned.end()) {
                    map[temp]++;
                    most=max(most,map[temp]);
                }
                temp="";
            } else {
                temp+=tolower(paragraph[i]);
            }
        }
        for(auto it=map.begin();it!=map.end();it++) {
            if(it->second==most) return it->first;
        }
        return "";
    }
};
// @lc code=end

