class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string temp=countAndSay(n-1);
        string ans;
        int count=1;
        for(int i=0;i<temp.size()-1;i++) {
            if(temp[i]==temp[i+1]) count++;
            else {
                ans.push_back(count+'0');
                ans.push_back(temp[i]);
                count=1;
            }
        }
        ans.push_back(count+'0');
        ans.push_back(temp[temp.size()-1]);
        return ans;
        
    }
};