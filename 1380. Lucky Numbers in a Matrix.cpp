class Solution {
public:
     int maxIndex(vector<vector<int>>& matrix,int m,int j){
        int max_val=0;
        for(int i=0;i<m;i++){
            if(matrix[i][j]>max_val){
                max_val=matrix[i][j]; 
            }
        }
    return max_val;
    }
     int minIndex(vector<vector<int>>& matrix,int n,int i){
        int min_val=100001;
        for(int j=0;j<n;j++){
            if(matrix[i][j]<min_val){
                min_val=matrix[i][j]; 
            }
        }
    return min_val;
    }
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size(); 
        vector<int>lucky;
        for(int i=0;i<m;i++){
            int min_val=minIndex(matrix,n,i) ; 
            for(int j=0;j<n;j++){
                int max_val=maxIndex(matrix,m,j) ; 
                if(min_val==matrix[i][j] && max_val==matrix[i][j]) lucky.push_back(matrix[i][j]);
            }
        }
    return lucky;
    }
};
