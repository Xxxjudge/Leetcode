class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans=0;
        int i=0;
        while(i<timeSeries.size()-1) {
            if(timeSeries[i+1]-timeSeries[i]>duration) ans-=timeSeries[i+1]-timeSeries[i]-duration;
            i++;
        }
        return ans+timeSeries[timeSeries.size()-1]-timeSeries[0]+duration;
    }
};