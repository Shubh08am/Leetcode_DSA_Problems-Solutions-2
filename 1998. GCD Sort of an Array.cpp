class DSU{
    public: 
    vector<int>rank,parent; 
    DSU(int n){
        rank.resize(n+1,0); 
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findUltimateParent(int node){
        return node==parent[node]?node:parent[node]=findUltimateParent(parent[node]);
    }
    void UnionByRank(int u,int v){
        int ulp_u=findUltimateParent(u);
        int ulp_v=findUltimateParent(v);
        if(u==v) return; 
        if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }
        else if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else{
            rank[ulp_v]+=1;
            parent[ulp_u]=ulp_v;
        }
    }
};
class Solution {
public:
    bool gcdSort(vector<int>& nums) {
        int n=nums.size();
        int N=*max_element(nums.begin(),nums.end());
        DSU ds(N);
        //MAKE THE GRAPH 
        for(auto&val:nums){
            for(int i=2;i*i<=val;i++){
                if(val%i==0){
                    ds.UnionByRank(val,i);
                    if(val/i!=i)  ds.UnionByRank(i,val/i);
                }
            }
        }
        
        //JUST CHECK WHENEVER NOT IN CORRECT POSITION CAN WE MAKE THEM SORTED BY SWAPING
        vector<int>original=nums;
        sort(original.begin(),original.end());
        for(int i=0;i<n;i++){
            int val1=original[i],val2=nums[i];
            if(val1!=val2){
                if(ds.findUltimateParent(val1)!=ds.findUltimateParent(val2)){
                    return false;
                }
            }
        }
    return true;
    }
};
