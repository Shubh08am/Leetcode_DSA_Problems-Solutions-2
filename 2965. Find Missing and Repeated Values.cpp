class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        map<int,int>mp; 
        vector<int>ans;
                     for(auto&it:grid) {
                         for(auto x:it) {
                             mp[x]++;
                         if(mp[x]>1) ans.push_back(x);
                            }
                     }
                      int n=grid.size();
                      for(int i=1;i<=n*n;i++){
                          if(mp[i]==0){ ans.push_back(i); return ans;}
                      }
                      return {};
    }
};
