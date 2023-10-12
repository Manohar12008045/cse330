class Solution {
public:
    int countPrimes(int n) {
        if(n <= 1) return 0;
        int ans = 0;
        vector<bool> prime(n, true);
        prime[1] = false;
        for(int i = 2; i < n; i++) {
            if(prime[i]) {
                ans++;
                for(int j = i; j < n; j += i) {
                    prime[j] = false;
                }
            }
        }
        return ans;
    }
};
