class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>>ans;
        for(int i=0;i<m;i++){
            vector<int>a;
            for(int j=0;j<n;j++) a.push_back(matrix[j][i]);
            ans.push_back(a);
        }
    return ans;
    }
};
