class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int length=flowerbed.size()+2;
        int n_real=0;
        if(length==2) return n==0;
        vector<int> temp;
        temp.push_back(0);
        for(auto x:flowerbed) temp.push_back(x);
        temp.push_back(0);
        for(int i=1;i<length-1;i++) {
            if(temp[i-1]==0&&temp[i]==0&&temp[i+1]==0) {
                n_real++;
                temp[i]=1;
            }
        }
        return n<=n_real;
    }
};