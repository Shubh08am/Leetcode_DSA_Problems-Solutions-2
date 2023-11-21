class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        map<char,vector<int>>mp;
        int n=s.size(),m=words.size(),subsequence =0;
        for(int i=0;i<n;i++) mp[s[i]].push_back(i);
        for(int i=0;i<m;i++){
            string w = words[i] ; 
            int sz = w.size(); 
            int val = -1 ;
            bool ok=0;
            for(int j=0;j<sz;j++){
                int ub = upper_bound(mp[w[j]].begin(),mp[w[j]].end(),val)-mp[w[j]].begin();
                if(ub!=mp[w[j]].size()) {
                    ok=1;
                    val=mp[w[j]][ub];
                }
                else{
                    ok=0;break;
                }
            }
          //  if(ok) cout<< w<<"\n";
            subsequence+=ok;
        }
    return subsequence ;
    }
};
