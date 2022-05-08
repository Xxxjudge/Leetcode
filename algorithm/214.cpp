class Solution {
public:
    bool palindable(string s) {
        int n=s.size();
        int mid=n/2;
        if(n%2==0) {
            int left=mid-1;
            int right=mid;
            while(left>=0) {
                if(s[left]!=s[right]) return false;
                left--;
                right++;
            }
        } else {
            int left=mid-1;
            int right=mid+1;
            while(left>=0) {
                if(s[left]!=s[right]) return false;
                left--;
                right++;
            }
        }
        return true;
    }
    string shortestPalindrome(string s) {
        int n=s.size();
        if(palindable(s)) return s;
        for(int i=n-2;i>=0;i--) {
            if(palindable(s.substr(0,i+1))) {
                string temp=s.substr(i+1,n-i-1);
                reverse(temp.begin(),temp.end());
                return temp+s;                
            }
        }
        string temp=s;
        reverse(temp.begin(),temp.end());
        return temp+s;;
    }
};