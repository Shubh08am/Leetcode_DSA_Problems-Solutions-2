class Solution {
public:
    bool rowCheck(vector<vector<int>>& mat,int row,int col){
        int m=mat[0].size();
        for(int i=0;i<m;i++){
            if(mat[row][i] && i!=col) return false;
        }
    return true;
    }
    bool colCheck(vector<vector<int>>& mat,int col,int row){
        int n=mat.size();
        for(int i=0;i<n;i++){
            if(mat[i][col] && i!=row) return false;
        }
    return true;
    }
    int numSpecial(vector<vector<int>>& mat) {
        queue<pair<int,int>>q; 
        int ans=0,n=mat.size(),m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]) q.push({i,j});
            }
        }
        while(!q.empty()){
            auto it = q.front();
            q.pop(); 
            int row=it.first;
            int col=it.second;
           // cout<<row<<" "<<col<<"\n";
           // cout<< rowCheck(mat,row,col) << " "<< colCheck(mat,col,row) <<"\n";
            ans+=(rowCheck(mat,row,col) && colCheck(mat,col,row));
        }
    return ans;
    }
};
