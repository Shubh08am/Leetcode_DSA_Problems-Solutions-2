class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
      int n=grid.size(),m=grid[0].size(); 
      vector<vector<int>>diff(n,vector<int>(m,0)),row=grid,col=grid;
      for(int i=0;i<n;i++){
          for(int j=0;j<m;j++) row[i][j]+=(j>0?row[i][j-1]:0);
      }
      for(int i=0;i<m;i++){
          for(int j=0;j<n;j++) col[j][i]+=(j>0?col[j-1][i]:0);
      }    
      for(int i=0;i<n;i++){
          for(int j=0;j<m;j++) diff[i][j]=2*row[i][m-1]+2*col[n-1][j]-n-m;
      } 
      return diff;
    }
};
