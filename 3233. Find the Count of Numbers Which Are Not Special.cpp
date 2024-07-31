class Solution {
public:
    bool prime(int n){
        for(int i=2;i*i<=n;i++){
            if(n%i==0) return false;
        }
        return true;
    }
    int nonSpecialCount(int l, int r) {
        int ans=r-l+1;
        for(int i=2;i*i<=r;i++){
            if(prime(i) && i*i<=r && i*i>=l) ans--;
        }
        return ans;
    }
};
