/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文字符串 Ⅱ
 */

// @lc code=start

class Solution {
public:
    bool isPalindrome(string s) {
        int left=0,right=s.size()-1;
        while(left<=right){
            if(s[left]!=s[right]) return false;
            left++;
            right--;
        }
            
        return true;
    }
    bool validPalindrome(string s) {
        int n=s.size();
        if(n<=1) return true;
        int left=0,right=n-1;
        bool deleteRight=false,deleteLeft=false;
        while(left<=right){
            if(s[left]!=s[right]) {
                if(s[left]==s[right-1]) {
                    if(isPalindrome(s.substr(left,right-left))) return true;
                } 
                if(s[left+1]==s[right]) {
                    if(isPalindrome(s.substr(left+1,right-left))) return true;
                }
                return false;
            } else {
                left++;
                right--;
            }
        }
        return true;
    }
};
// @lc code=end

