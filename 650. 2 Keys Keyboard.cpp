class Solution {
public:
    int solve(int i,int j,int n,vector<vector<int>>&dp){
        if(i==n) return 0;
        if(i>n) return 1e5;
        if(dp[i][j]!=-1) return dp[i][j];
        int take = 2+solve(i*2,i,n,dp);
        int notTake=1+solve(i+j,j,n,dp);
        return dp[i][j]=min(take,notTake);
    }
    int minSteps(int n) {
        if(n==1) return 0;
        vector<vector<int>>dp(n+1,vector<int>(n/2+1,-1));
        return 1 + solve(1,1,n,dp);
    }
};
