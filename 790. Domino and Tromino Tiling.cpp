class Solution {
public:
    const int mod=1e9+7;
    int numTilings(int n) {
        vector<int>dp(1001,0);
        dp[1]=1;
        dp[2]=2;
        dp[3]=5;
        for(int i=4;i<=n;i++){
            dp[i] = (1ll*dp[i-1]*2+1ll*dp[i-3])%mod;
        }
        return dp[n];
    }
};
