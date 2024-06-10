class Solution {
public:
    map<int,int>dp;
    int solve(int i, int s,vector<int>&r){
        int n = r.size();
        if(i >= n){
            return 0;
        }
        if(dp.find(s) != dp.end()){
            return dp[s];
        }
        auto it = upper_bound(r.begin(), r.end(), s + r[i]);
        int pos = it - r.begin();
        int t = r[i] + solve(pos, s + r[i],r);
        int nt = solve(i+1, s,r);
        return dp[s] = max(t, nt);
    }
    
    int maxTotalReward(vector<int>& r) {
        sort(r.begin(), r.end());
        return solve (0, 0,r);
    }
};
