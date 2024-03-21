class Solution {
public:
    int dp[101][101] ;
    const int mod = 1e9+7;
    int solve(int ind,vector<int>&nums,int k){
        int n = nums.size(); 
        if(ind==n) return k==0 ; 
        if(k<0) return  0 ;
        int &val = dp[ind][k] ; 
        if(val!=-1) return val ;
        
        //take not take 
       int take = solve(ind+1,nums,k-nums[ind])%mod ; 
       int notTake = solve(ind+1,nums,k)%mod ; 

    return val=(1ll*(take+1ll*2*notTake))%mod;
    }
    int sumOfPower(vector<int>& nums, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(0,nums,k);
    }
};
