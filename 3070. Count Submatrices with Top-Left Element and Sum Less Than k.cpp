class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        vector<vector<int>>prefix=grid; 
        int n=grid.size(),m=grid[0].size(),ans=0; 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){ 
                prefix[i][j] = prefix[i][j] + (j>0?prefix[i][j-1]:0);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                prefix[i][j] = prefix[i][j] + (i>0?prefix[i-1][j]:0);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) ans+=prefix[i][j]<=k ;
        }
        return ans;
    }
};
