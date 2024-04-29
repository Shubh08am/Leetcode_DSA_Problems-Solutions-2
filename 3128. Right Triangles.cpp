#define ll long long
class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& g) {
        unordered_map<ll,ll>r,c;
        ll m=g.size(),n=g[0].size(),a=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(g[i][j]==1){
                    r[i]++;
                    c[j]++;
                }
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(g[i][j]==1){
                    ll b = r[i]-1 , d = c[j]-1;
                    a+= 1ll*b*d;
                }
            }
        }
        return a;
    }
};
