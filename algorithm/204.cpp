class Solution {
public:

    int countPrimes(int n) {
        if(n<=2) return 0;
        vector<int> isprime(n,1);
        int ans=0;
        for(int i=2;i<n;i++) {
            if(isprime[i]) {

                if((long long) i*i<n){
                    for(int j=i*i;j<n;j=j+i) {
                        isprime[j]=0;
                    }
                }
                ans++;
            }
        }
        return ans;
    }
    
};