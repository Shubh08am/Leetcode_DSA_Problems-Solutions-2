class Solution {
public:
    int mod = 1e9+7;
    int numberOfWays(string corridor) {
        int n = corridor.size();
        vector<vector<int>> dp(n+1 , vector<int> (3 , 0));
        dp[n][2]=1;
        for(int i=n-1 ; i>=0 ; i--){
            for(int s=0 ; s<=2 ; s++){
                if(s==2){
                    if(corridor[i] == 'P'){
                        dp[i][s] = (dp[i+1][s]%mod + dp[i+1][0]%mod) %mod;
                    }
                    else{
                        dp[i][s] = dp[i+1][1] % mod;
                    }
                }
                else{
                    dp[i][s] = dp[i+1][s+(corridor[i]=='S')] % mod;
                }
            }
        }
        return dp[0][0]%mod;
    }
};
