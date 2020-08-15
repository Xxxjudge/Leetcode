class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle=="") return 0;
        return haystack.find(needle);
    }
};
//库函数大法好