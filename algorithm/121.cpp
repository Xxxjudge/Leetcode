class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = 1e9;
        int maxprofit = 0;
        for (auto x:prices) {
            minprice=min(minprice,x);
            maxprofit=max(maxprofit,x-minprice);
        }
        return maxprofit;
    }
};