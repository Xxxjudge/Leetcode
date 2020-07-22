class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        char c;
        for(int x=0;x<s.size();x++) {
            if(s[x]=='{'||s[x]=='['||s[x]=='(') st.push(s[x]);
            else {
                if(st.empty()) return false;
                c=st.top();
                if(c=='{'&&s[x]!='}') return false;
                if(c=='('&&s[x]!=')') return false;
                if(c=='['&&s[x]!=']') return false;
                st.pop();
            }
        }
        return st.empty();
    }
};