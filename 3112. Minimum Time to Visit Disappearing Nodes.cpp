class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<int>ans(n,-1) ; 
        vector<pair<int,int>>adj[n] ; 
        for(auto&it : edges){
            int u=it[0] , v=it[1] , w=it[2] ;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; 
        pq.push({0,0}) ; 
        while(!pq.empty()){
            auto it = pq.top(); 
            pq.pop();
            int dis = it.first , node = it.second ; 
            if(ans[node]!=-1) continue; 
            ans[node]=dis;
            for(auto&[x,y] : adj[node]){
                if(dis+y<disappear[x]){
                    pq.push({dis+y,x});
                }
            }
        }
    return ans;
    }
};
