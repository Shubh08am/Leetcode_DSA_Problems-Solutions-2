class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        map<int,int>freq; 
        for(int i=0;i<n;i++) freq[i]=i+1;
        vector<int>dist;
        for(auto&it:queries){
            int u=it[0],v=it[1]; 
            auto ub = freq.upper_bound(v-1);
            auto lb = freq.lower_bound(u+1);
            freq.erase(lb,ub); 
            dist.push_back(freq.size()-1);
        }
        return dist;
    }
};
