class Solution {
    int dp[33];
public:
    int fibon(int n) {
        cout<<n<<endl;
        if(n==1)return 1;
        if(n<=0)return 0;

        int& ans = dp[n];
        if(ans!=-1)return ans;

        return ans = fibon(n-1) + fibon(n-2);
    }

     int fib(int n){
        for(int i = 0 ; i < 33 ; i++)dp[i]=-1;
        int ans = fibon(n);
        cout<<ans<<endl;
        return ans;
    }
};
