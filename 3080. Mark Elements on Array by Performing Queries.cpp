#define ll long long 
class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& q) {
        int n = nums.size(),m=q.size();
        vector<ll>an(m); 
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>Q; 
        ll c=0,i=0; 
        unordered_map<ll,ll>freq;
        for(auto&it:nums){
            Q.push({it,i});
            i++;
            c+=it;
        }
        for(int i=0;i<m;i++){
            ll a = q[i][0],b=q[i][1],ok=0; 
            if(!freq[a]) {freq[a]=1;c-=nums[a];}
            while(b>0 && !Q.empty()){
                auto it = Q.top();
                ll d = it.first , e = it.second ; 
                Q.pop();
                if(freq[e]!=1){
                    freq[e]=1;
                    c-=d;
                    b--;
                    ok=1;
                }
            }
            if(!ok && Q.empty()) break;
            an[i]=c;
        }
        return an;
    }
};
