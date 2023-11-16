#define ll long long 
class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        priority_queue<ll>pq;
        for(auto &it:values){
            for(auto&x:it) pq.push(x);
        }
        ll ans=0,sz=pq.size();
        while(!pq.empty()){
            ans+=sz*pq.top();
            pq.pop();
            sz--;
        }
    return ans;
    }
};
