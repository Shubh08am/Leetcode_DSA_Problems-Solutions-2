class Solution {
public:
    int minimumArea(vector<vector<int>>& g) {
        int n = g.size() , m = g[0].size(),h=-1,w=-1,h2=1e9,w2=1e9; 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]==1){
                    h=max(h,j); 
                    w=max(w,i);
                    h2=min(h2,j); 
                    w2=min(w2,i);
                }
            }
        }
     //   cout<<h<<" "<<w<<"\n";
        if(h==-1 or w==-1 or h2==1e9 or w2==1e9) return 0; 
        h=h-h2+1;w=w-w2+1; 
        return h*w;
    }
};
