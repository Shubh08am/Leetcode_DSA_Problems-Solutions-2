#define ll long long
class Solution {
public:
    ll dp[1001][1001];
    ll solve(ll ind,ll prev,vector<int>& prices){
        int n = prices.size(); 
        if(ind>=n) return 0;
        ll &val = dp[ind][prev]; 
        if(val!=-1) return val; 
        val=0;
        if(prev>0){
            ll prev2 = prev-1;
         ll nt = solve(ind+1,prev2,prices) ; 
        ll t = prices[ind]+solve(ind+1,ind+1,prices) ; 
        return val=min(nt,t);
        }
        else{
        ll t = prices[ind]+solve(ind+1,ind+1,prices) ; 
    return val=t;
        }
    } 
    int minimumCoins(vector<int>& prices) {
        memset(dp,-1,sizeof(dp)); 
        int n = prices.size(); 
        return solve(0,0,prices);
    }
};
