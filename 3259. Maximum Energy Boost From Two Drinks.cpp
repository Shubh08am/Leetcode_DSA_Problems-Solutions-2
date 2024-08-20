class Solution {
public:
    long long solve(int ind,int turn,int n,vector<int>&energyDrinkA,vector<int>&energyDrinkB,vector<vector<long long>>&dp){
        if(ind>=n) return 0; 
        if(dp[ind][turn]!=-1) return dp[ind][turn]; 
        long long ans=0; 
        if(turn==0){
            long long option1 = energyDrinkA[ind] + solve(ind+1,0,n,energyDrinkA,energyDrinkB,dp);
            long long option2 = energyDrinkA[ind] + solve(ind+2,1,n,energyDrinkA,energyDrinkB,dp);
            ans=max(option1,option2);
        }
        else{
            long long option1 = energyDrinkB[ind] + solve(ind+1,1,n,energyDrinkA,energyDrinkB,dp);
            long long option2 = energyDrinkB[ind] + solve(ind+2,0,n,energyDrinkA,energyDrinkB,dp);
            ans=max(option1,option2);
        }
        return dp[ind][turn] = ans ; 
    }
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n=energyDrinkA.size(); 
        vector<vector<long long>>dp(n,vector<long long>(2,-1));
        return max(solve(0,0,n,energyDrinkA,energyDrinkB,dp),solve(0,1,n,energyDrinkA,energyDrinkB,dp));
    }
};
