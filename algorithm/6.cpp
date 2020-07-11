class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> temp(numRows);
        string ans;
        if(s.empty()||numRows==1) return s;
        int div=2*numRows-2;
        for(int i=0;i<s.size();i++){
            if(i%div<numRows)
            temp[i%div].push_back(s[i]);
            if(i%div>=numRows)
            temp[div-i%div].push_back(s[i]);
        }
        for(int i=0;i<numRows;i++) ans+=temp[i];
        return ans;
    }
};
//按V作为一个部分，进行求解，分别进行操作。