class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char,int> M;
        string firstLine="qwertyuiop";
        string secondLine="asdfghjkl";
        string thirdLine="zxcvbnm";
        vector<string> ans;
        for(auto c:firstLine) {
            pair<char,int> temp(c,0);
            M.insert(temp);
        }
        for(auto c:secondLine) {
            pair<char,int> temp(c,1);
            M.insert(temp);
        }
        for(auto c:thirdLine){
            pair<char,int> temp(c,2);
            M.insert(temp);
        }
        for(int i=0;i<words.size();i++) {
            for(int k=0;k<3;k++) {
                for(int j=0;j<words[i].size();j++) {
                    if(M.find(words[i][j])!=M.end()&&M[words[i][j]]!=k)
                        break;
                    else if(M.find(words[i][j]+32)!=M.end()&&M[words[i][j]+32]!=k) break;
                    else if(j==words[i].size()-1) 
                        ans.push_back(words[i]);
                }
            }
        }
        return ans;
    }
};