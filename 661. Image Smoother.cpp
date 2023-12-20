class Solution {
public:
    bool isValid(int n,int m,int nr,int nc){
        return nr>=0 && nr<n && nc>=0 && nc<m ;
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n=img.size(),m=img[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cost=0,total=0;
                    for(int xi=-1;xi<=1;xi++){
                        for(int xj=-1;xj<=1;xj++){
                            int nr = i + xi ; 
                            int nc = j + xj ; 
                            if(isValid(n,m,nr,nc)){
                                total++;
                                cost+=img[nr][nc];
                            }
                        }
                    }
                ans[i][j] = cost/total ;
            }
        }
    return ans;
    }
};
