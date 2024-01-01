class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int ans=-1,n=s.size();
vector<pair<int,pair<int,int>>>pos(26,{0,{1e9,1e9}});
for(int i=0;i<n;i++){
pos[s[i]-'a'].second.first=min(pos[s[i]-'a'].second.first,i);
pos[s[i]-'a'].second.second=i;
    if(pos[s[i]-'a'].second.second!=1e9 && pos[s[i]-'a'].second.first!=1e9)
ans = max(ans,pos[s[i]-'a'].second.second-pos[s[i]-'a'].second.first-1);
}
return ans;
    }
};
