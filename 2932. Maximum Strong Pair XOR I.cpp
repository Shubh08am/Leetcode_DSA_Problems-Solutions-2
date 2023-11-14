class Solution {
public:
    int maximumStrongPairXor(vector<int>& n) {
        int m=n.size(),a=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                if(abs(n[i]-n[j])<=min(n[i],n[j])){
                    a=max(a,(n[i]^n[j]));
                }
            }
        }
        return a;
    }
};
