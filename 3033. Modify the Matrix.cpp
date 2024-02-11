class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& m) {
        int a = m.size(),b= m[0].size();
        vector<int> c(b, -2);
        for (int j = 0; j < b; j++) {
            for (int i = 0; i < a; i++) {
                if (m[i][j] > c[j])       c[j] = m[i][j];
            }
        }
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                if (m[i][j] == -1)   m[i][j] = c[j];
            }
        }
        return m;
    }
};
