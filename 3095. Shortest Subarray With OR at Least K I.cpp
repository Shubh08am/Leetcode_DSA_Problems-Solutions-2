class Solution {
public:
    int minimumSubarrayLength(vector<int>& n, int k) {
        int m=n.size(),ans=1e9; 
        for(int i=0;i<m;i++){
            int v=0;
            for(int j=i;j<m;j++){
                v=(v|n[j]) ;
             //   cout << v << " ";
                if(v>=k){
                    ans=min(ans,j-i+1);
                }
            }
        }
        return ans==1e9?-1:ans;
    }
};
