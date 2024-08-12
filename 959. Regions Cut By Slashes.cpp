class Solution {
private:
    bool isValidCell(vector<vector<int>>& grid, int row,int col) {
        int n = grid.size();
        return row >= 0 && col >= 0 && row < n && col < n && grid[row][col] == 0;
    }
    vector<pair<int,int>> DIRECTIONS = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void floodFill(vector<vector<int>>& grid, int row, int col) {
        queue<pair<int, int>> q;
        grid[row][col] = 1;
        q.push({row, col});
        while (!q.empty()) {
            auto [currentRow, currentCol] = q.front();
            q.pop();
            for (auto& direction : DIRECTIONS) {
                int newRow = direction.first + currentRow;
                int newCol = direction.second + currentCol;
                if (isValidCell(grid, newRow, newCol)) {
                    grid[newRow][newCol] = 1;
                    q.push({newRow, newCol});
                }
            }
        }
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> g(n * 3, vector<int>(n * 3, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int baseRow = i * 3;
                int baseCol = j * 3;
                 if (grid[i][j] == '\\') {
                    g[baseRow][baseCol] = 1;
                    g[baseRow + 1][baseCol + 1] = 1;
                    g[baseRow + 2][baseCol + 2] = 1;
                } 
                else if (grid[i][j] == '/') {
                    g[baseRow][baseCol + 2] = 1;
                    g[baseRow + 1][baseCol + 1] = 1;
                    g[baseRow + 2][baseCol] = 1;
                }
            }
        }
        int total = 0;
        for (int i = 0; i < n * 3; i++) {
            for (int j = 0; j < n * 3; j++) {
                if (g[i][j] == 0) {
                    floodFill(g, i, j);
                    total++;
                }
            }
        }
        return total;
    }
};
