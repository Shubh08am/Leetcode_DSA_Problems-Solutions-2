class Solution {
public:
    string lastNonEmptyString(string s) {
         map<char, int>mp,vis;
         string res;
        int m = 0, n = s.size();
        for(int i = 0; i < n; i++){
            mp[s[i]]++;
            m = max(m, mp[s[i]]);
        }
        for(int i = n-1; i >= 0; i--){
            if(mp[s[i]] == m && vis[s[i]]==0){
                vis[s[i]] =1;
                res+= s[i];
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
