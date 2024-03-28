#define ll long long 
class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        int n = nums.size(); 
        vector<ll>v ; 
        map<ll,ll>mp ; 
        set<pair<ll,ll>>s ; 
        ll maxf=0 ; 
        
        for(int i=0;i<n;i++){
            ll val = nums[i] ;
            s.erase({mp[val],val}) ; 
            ll occ = mp[val] + freq[i] ; 
            mp[val] = occ ; 
            s.insert({mp[val],val}); 
            auto it = s.rbegin(); 
            ll maxf = it->first ; 
            v.push_back(maxf) ; 
        }
        return v;
    }
};
