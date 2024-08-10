class Solution {
public:
    int dijkstra(int n,vector<vector<int>>&adj){
        vector<int>dist(n,1e5); 
        dist[0]=0;
        queue<pair<int,int>>q;
        q.push({0,0});
        while(!q.empty()){
            auto it=q.front();
            q.pop(); 
            int node=it.second,dis=it.first; 
            if(node==n-1) break;
            for(auto&it:adj[node]){
                if(dis+1<dist[it]){
                    dist[it]=dis+1;
                    //cout<<it<<" "<<dist[it]<<"\n";
                    q.push({dis+1,it});
                }
            }
        }          
        return dist[n-1];
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>adj(n+1); 
        for(int i=0;i<n;i++){
            adj[i].push_back(i+1);
        }
        vector<int>ans;
        for(auto&it:queries){
            int u=it[0],v=it[1]; 
            adj[u].push_back(v);
            int d=dijkstra(n,adj);
            ans.push_back(d);
        }
        return ans;
    }
};
