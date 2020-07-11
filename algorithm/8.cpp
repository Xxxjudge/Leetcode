class Solution {
public:
    int myAtoi(string str) {
        string state="start";
        int sign=1;
        long long ans=0;
        unordered_map<string,vector<string>> table={
            {"start",{"start","signal","in_number","end"}},
            {"signal",{"end","end","in_number","end"}},
            {"in_number",{"end","end","in_number","end"}},
            {"end",{"end","end","end","end"}}
        };
        for(int i=0;i<str.size();i++){
            state=table[state][get_state(str[i])];
            if(state=="signal"){
                sign=str[i]=='+'?1:-1;
            }
            if(state=="in_number"){
                ans=ans*10+str[i]-'0';
                ans=(sign==1)?min(ans,(long long)INT_MAX):min(ans,-(long long)INT_MIN);
            }
            if(state=="end") break;
        }
        ans=(sign==1)?ans:-ans;
        return ans;
    }
    int get_state(char c){
        if(isspace(c)) return 0;
        if(c=='-'||c=='+') return 1;
        if(isdigit(c)) return 2;
        return 3;
    }
};
//用了自动机，官方答案，时间10%，内存5%