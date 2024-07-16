class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& h, vector<int>& v) {
        sort(h.begin(), h.end(),greater<int>());
        sort(v.begin(), v.end(),greater<int>());

        long long sq = 0, i=0,j=0,x=1,y=1; 
        
        for(i=0,j=0;i<m-1 && j<n-1;){
            if(h[i]<=v[j]){
                sq=sq+1ll*x*v[j];
                y++;j++;
            }
            else if(h[i]>v[j]){
                sq=sq+1ll*y*h[i];
                x++;i++;
            }
        }
        for(;i<m-1;i++){
                sq=sq+1ll*y*h[i];
        }
         for(;j<n-1;j++){
                sq=sq+1ll*x*v[j];
        }
        return sq;
    }
};
