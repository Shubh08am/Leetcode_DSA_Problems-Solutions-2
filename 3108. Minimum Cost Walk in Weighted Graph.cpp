
class DSU
{
    vector<int> rank, parent, size;

public:
    DSU(int n){
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int node){
        if (node == parent[node])
            return node;
        return parent[node] = find(parent[node]);
    }

    void union_rank(int u, int v){
        int ulp_u = find(u);
        int ulp_v = find(v);
        if (ulp_u == ulp_v){
            return;
        }
        if (rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void union_size(int u, int v){
        int ulp_u = find(u);
        int ulp_v = find(v);
        if (ulp_u == ulp_v){
            return;
        }
        if (size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};


class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DSU d(n);
        for(int i=0 ; i<edges.size() ; i++){
            d.union_size(edges[i][0],edges[i][1]);
        }
        map<int,int> mp;
        for(int i=0 ; i<edges.size() ; i++){
            if(d.find(edges[i][0])==d.find(edges[i][1])){
                int p=d.find(edges[i][0]);
                if(mp.count(p)){
                    mp[p]&=edges[i][2];
                }   
                else{
                    mp[p]=edges[i][2];
                }
            }
        
        }
        vector<int> ans;
        for(auto q : query ){
            if(q[0]==q[1]){
                ans.push_back(0);
                continue;
            }
            if(d.find(q[0])==d.find(q[1])){
                int p=d.find(q[0]);
                ans.push_back(mp[p]);
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
