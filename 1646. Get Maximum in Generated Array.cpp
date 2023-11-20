class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<int>v(201,0); 
        v[1]=1;
        for(int i=1;i<=n;i++){
            int pos = 2*i; 
             v[pos]=v[i];
            if(pos+1<=n) v[pos+1] = v[i]+v[i+1];
        }
    return n==0?0:*max_element(v.begin(),v.end());
    }
};
