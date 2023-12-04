class Solution {
public:
    bool isV(char ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' ;
    }
    int beautifulSubstrings(string s, int k) {
        int n = s.size();
        long long cnt=0; 
        for(int i=0;i<n;i++){
            int v= isV(s[i]) ; 
            int c = (v>0?0:1);
            for(int j=i+1;j<n;j++){
                v+=isV(s[j]) ;
                c+=(!(isV(s[j])));
                if(v==c){
                    long long prd = (1ll*v*c)%k; 
                    if(prd==0) cnt++;
                }
            }
        }
        return cnt;
    }
};
