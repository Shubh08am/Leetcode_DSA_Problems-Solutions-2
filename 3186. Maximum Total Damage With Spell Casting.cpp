#define ll long long
class Solution {
public:
    int nextPos(int low,int high,int value,vector<int>&power){
        while(low<=high){
            int mid=low+(high-low)/2; 
            if(power[mid]>=value){
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
    ll solve(int ind,vector<int>&power,unordered_map<int,int>&Freq,vector<ll>&dp){
        int n=power.size(); 
        if(ind>=n) return 0; 
        if(dp[ind]!=-1) return dp[ind];
        ll notTake=solve(ind+1,power,Freq,dp); 
       // int pos = nextPos(ind,n-1,power[ind]+3,power); 
        int pos = lower_bound(power.begin(),power.end(),power[ind]+3)-power.begin(); 
        ll take = 1ll*Freq[power[ind]]*power[ind] + solve(pos,power,Freq,dp);
        return dp[ind] = max(take,notTake);
    }
    ll tabulation(vector<int>& power,unordered_map<int,int>&Freq){
        int n=power.size(); 
        vector<ll>dp(n+1,0);
        for(int ind=n-1;ind>=0;ind--){
            ll notTake=dp[ind+1]; 
            //int pos = nextPos(ind,n-1,power[ind]+3,power);  
            int pos = lower_bound(power.begin(),power.end(),power[ind]+3)-power.begin(); 
            ll take = 1ll*Freq[power[ind]]*power[ind] + dp[pos];
            dp[ind]=max(take,notTake);
        }
        return dp[0]; 
    }
    long long maximumTotalDamage(vector<int>& power) {
        int n=power.size(); 
        unordered_map<int,int>Freq; 
        for(auto&p:power) Freq[p]++; 
        sort(power.begin(),power.end());
      //  vector<ll>dp(n+1,-1);
      //  return solve(0,power,Freq,dp);
        return tabulation(power,Freq);
    }
};
