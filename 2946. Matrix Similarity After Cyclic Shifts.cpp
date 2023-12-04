class Solution {
public:
    vector<int>shift(vector<int>& mat, int k) {
        int m = mat.size(); k%=m;
        vector<int>a(m);
        for(int i=0;i<m;i++) a[(i+k+m)%m]=mat[i];
        return a;
    }
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size() , n=mat[0].size(); 
        vector<vector<int>>mm;
        mm=mat;
       
        //now shift 
        for(int i=0;i<m;i++){
            if(!(i&1)){
                mat[i]=shift(mat[i],-k);
            }
            else if(i&1){
                mat[i]=shift(mat[i],k);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++) {
                if(mat[i][j]!=mm[i][j]) return false;
            }
        }
        return true;
    }
};
