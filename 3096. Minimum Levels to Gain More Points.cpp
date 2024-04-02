class Solution {
public:
    int minimumLevels(vector<int>& p) {
        int n=p.size(),ans=0,c=0,d=0; 
        int zero = count(p.begin(),p.end(),0) ; 
        int one = count(p.begin(),p.end(),1) ; 
        int s = one-zero ; 
        for(int i=0;i<n;i++) {
if(p[i]==0) p[i]=-1; 
        }
        for(int i=0;i<n-1;i++){
             ans+=p[i] ; 
             int diff = s; 
            if(1ll*2*ans > s) return i+1;
        }
        return -1;
    }
};
