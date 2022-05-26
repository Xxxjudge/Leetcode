/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */

// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {
        int n=s.size();
        int left=0,right=n-1;
        unordered_set<char> myset;
        myset.insert('a');myset.insert('e');myset.insert('i');myset.insert('o');myset.insert('u');
        myset.insert('A');myset.insert('E');myset.insert('I');myset.insert('U');myset.insert('O');
        while(left<right) {
            while(left<right&&myset.find(s[left])==myset.end()) left++;
            while(left<right&&myset.find(s[right])==myset.end()) right--;
            if(left<right) {
                char temp=s[left];
                s[left]=s[right];
                s[right]=temp;
                left++;
                right--;
            }
        }
        return s;
    }
};
// @lc code=end

