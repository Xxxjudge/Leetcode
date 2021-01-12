class Solution {
public:
    bool isPalindrome(string s) {
        int i=0,j=s.size()-1;
        while(i<j) {
            if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||(s[i]>='0'&&s[i]<='9')) {
                if((s[j]>='a'&&s[j]<='z')||(s[j]>='A'&&s[j]<='Z')||(s[j]>='0'&&s[j]<='9')) {
                    if(s[i]==s[j]) {
                        i++;
                        j--;
                    } else if(isdigit(s[i])||isdigit(s[j])){
                        return false;
                    } else if(abs(s[i]-s[j])==32) {
                        i++;
                        j--;
                    } else {
                        return false;
                    }
                } else {
                    j--;
                }
            } else i++;            
        }
        return true;
    }
};