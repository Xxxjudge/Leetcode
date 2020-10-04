class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> num={a,b,c};
        sort(num.begin(),num.end());
        vector<int> ans={1,num[2]-num[0]-2};
        if(num[1]==num[0]+1&&num[2]==num[1]+1) ans[0]=0;
        else if(num[1]>num[0]+2&&num[2]>num[1]+2) ans[0]=2;        
        return ans;
    }
};