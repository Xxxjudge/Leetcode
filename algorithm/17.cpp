class Solution {
public:
void backtrack(vector<string>& ans,unordered_map<char,string> phoneMap,string digits,string temp,int index,int n) {
            if(index==n) ans.push_back(temp);
            else {
                char num=digits[index];
                string s=phoneMap.at(num);
                for(auto x:s) {
                    temp+=x;
                    backtrack(ans,phoneMap,digits,temp,index+1,n);
                    temp.pop_back();
                }

            }
        }
    vector<string> letterCombinations(string digits) {
        int n=digits.size();

        vector<string> ans;
        if(n==0) return ans;
        unordered_map<char, string> phoneMap{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        string temp;        
        backtrack(ans,phoneMap,digits,temp,0,n);
        return ans;

    }
};