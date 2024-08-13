class Solution {
public:
    int solve(int node,int parent,vector<int>adj[],int &goodNodes){
        int subtreesize=0;
        set<int>s;
        for(auto&it:adj[node]){
            if(it!=parent){
                int currsubtreesize=solve(it,node,adj,goodNodes);
                subtreesize+=currsubtreesize;
                s.insert(currsubtreesize);
            }
        }
        goodNodes+=(s.size()<=1);
        return 1+subtreesize;
    }
    int countGoodNodes(vector<vector<int>>& edges) {
        //DFS 
        int n=edges.size();
        vector<int>adj[n+1];
        for(auto&it:edges){
            int u=it[0],v=it[1]; 
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int goodNodes=0; 
        solve(0,-1,adj,goodNodes);
        return goodNodes; 
    }
};
