class neighborSum {
public:
    map<int,pair<int,int>>mp;
    vector<vector<int>> grid;
    neighborSum(vector<vector<int>>& grid) {
        int n=grid.size(); 
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) mp[grid[i][j]]={i,j};
        }
        this->grid=grid;
    }
    
    int adjacentSum(int value) {
        int n=grid.size(); 
        auto it = mp[value]; 
        int i=it.first,j=it.second,ans=0; 
        if(i-1>=0 && j>=0) ans+=grid[i-1][j]; 
        if(j-1>=0 && i>=0) ans+=grid[i][j-1];
        if(i+1<n && j>=0) ans+=grid[i+1][j]; 
        if(j+1<n && i>=0) ans+=grid[i][j+1]; 
        return ans;
    }
    
    int diagonalSum(int value) {
        int n=grid.size(); 
        auto it = mp[value]; 
        int i=it.first,j=it.second,ans=0; 
        if(i-1>=0 && j-1>=0) ans+=grid[i-1][j-1]; 
        if(i-1>=0 && j+1<n) ans+=grid[i-1][j+1];
        if(i+1<n && j-1>=0) ans+=grid[i+1][j-1]; 
        if(j+1<n && i+1<n) ans+=grid[i+1][j+1]; 
         return ans;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */
