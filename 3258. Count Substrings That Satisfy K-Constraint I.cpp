class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int cnt=0,n=s.size(); 
        for(int i=0;i<n;i++){
            int zero = (s[i]=='0') , one = (s[i]=='1') ; 
            for(int j=i+1;j<n;j++){
                zero+=(s[j]=='0');
                one+=(s[j]=='1');
                if(zero<=k or one<=k) cnt++;
            }
        }
        return cnt+n;
    }
};
