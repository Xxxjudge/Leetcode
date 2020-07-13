class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count=0;
        int sum=0;
        for(int i=0;i<k;i++) sum+=arr[i];
        if(sum>=k*threshold) count++;
        for(int i=0;i<arr.size()-k;i++){
            sum+=arr[i+k];
            sum-=arr[i];
            if(sum>=k*threshold) count++;
        }
        return count;
    }
};
//滑动窗口