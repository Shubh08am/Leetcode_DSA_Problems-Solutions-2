class Solution {
public:
    void floydWarshall(vector<vector<long long>>&dist){
        for(int i=0;i<26;i++) dist[i][i]=0;
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(dist[i][k]==INT_MAX || dist[k][j]==INT_MAX) continue;
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n=original.size(),m=source.size();
         //find all the distance between all the nodes 
        vector<vector<long long>>dist(26,vector<long long>(26,INT_MAX)); 
        for(int i=0;i<n;i++){
            int u=(original[i]-'a'); 
            int v=(changed[i]-'a');
            long long wt=cost[i]; 
            dist[u][v]=min(dist[u][v],wt);
        }
        floydWarshall(dist);
        long min_cost=0;
        for(int i=0;i<m;i++){
            int u=(source[i]-'a'); 
            int v=(target[i]-'a');
            long long curr_cost=dist[u][v];
            if(curr_cost>=INT_MAX) return -1;
            else min_cost+=curr_cost;
        }
        return min_cost;
    }
};
