class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char>s(jewels.begin(),jewels.end());
        int ans=0;
        for(auto it : stones) ans+=s.count(it);
        return ans;
    }
};
