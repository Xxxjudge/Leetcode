class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0) return 0;
        stack<int> s;
        s.push(prices[0]);
        int bottom=s.top();
        int max=0;
        vector<int> temp=prices;
        temp.push_back(0);
        for(int i=1;i<=n;i++) {
            if(temp[i]>=s.top()) s.push(temp[i]);
            else {
                while(!s.empty()&&temp[i]<s.top()) {
                    max=(max>(s.top()-bottom))?max:(s.top()-bottom);
                    s.pop();
                }
                if(s.empty()) {
                    s.push(temp[i]);
                    bottom=s.top();
                } else s.push(temp[i]);
            }
        }
        return max;

    }
};