class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxLength=0;
        for(int i=0;i<left.size();i++) maxLength=max(maxLength,left[i]);
        for(int i=0;i<right.size();i++) maxLength=max(maxLength,n-right[i]);
        return maxLength;
    }
};