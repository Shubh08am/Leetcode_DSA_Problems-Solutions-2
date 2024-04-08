class Solution {
public:
    int maxDepth(string s) {
        int ans=0,depth=0; 
        for(auto&ch:s){
            ans=max(ans,ch=='('?++depth:ch==')'?--depth:depth);
        }
    return ans;
    }
};
