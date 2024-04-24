#define ll long long 
class Solution {
public:
    ll solve(string&s,ll ind,ll prev,ll tar,vector<vector<vector<ll>>>&dp){
        int n = s.size(); 
        if(tar==3) return 1; 
        if(ind>=n) return 0; 
        ll &val = dp[ind][prev+1][tar];
        if(val!=-1) return val;
        ll notTake = solve(s,ind+1,prev,tar,dp);
        ll take=0; 
        if(prev==-1 || (s[ind]-'0')!=prev){
            take=solve(s,ind+1,(s[ind]-'0'),tar+1,dp);
        }
        //cout << take << " "<< notTake << "\n";
    return val=take+notTake;
    }
    long long numberOfWays(string s) {
        int n = s.size(); 
        //4 ->1 2 3 stored
        //2 -> 0 1 stored and prev=-1 therefore make it of size 3
        vector<vector<vector<ll>>>dp(n+1,vector<vector<ll>>(3,vector<ll>(4,-1)));
        return solve(s,0,-1,0,dp);
    }
};
