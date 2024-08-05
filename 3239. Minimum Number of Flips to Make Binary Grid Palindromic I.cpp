class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size(), a=0,b=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m/2;j++){
                if(grid[i][j]!=grid[i][m-j-1]){
                    a++;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j =0;j<n/2;j++){
                if(grid[j][i]!=grid[n-j-1][i]){
                    b++;
                }
            }
        }
        return min(a,b);
    }
};
