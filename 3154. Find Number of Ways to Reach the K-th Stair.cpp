#define ll long long
class Solution {
public:
    map<pair<ll,pair<ll,ll>>,ll>dp; 
    int solve(ll ind,int jump,int k,int turn){
        if(jump>32) return 0;
        if(dp.count({ind,{jump,turn}})) return dp[{ind,{jump,turn}}] ;
        ll ans=solve(ind+(1ll<<jump),jump+1,k,1)+(ind==k);
        if(turn==1 && ind>0) ans+=solve(ind-1,jump,k,0);
        return dp[{ind,{jump,turn}}]=ans;
    }
    int waysToReachStair(int k) {
        return solve(1,0,k,1);
    }
};
