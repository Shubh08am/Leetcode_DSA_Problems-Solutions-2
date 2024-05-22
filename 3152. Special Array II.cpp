class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(),m=queries.size(); 
        vector<bool>ans(m,true); 
        vector<int>pre(n,0); 
        pre[0]=1; 
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+(nums[i]%2!=nums[i-1]%2);
        }
        for(auto it : pre) cout<<it<<" ";
        cout<<"\n";

        for(int i=0;i<m;i++){
            int to=queries[i][1],from=queries[i][0]; 
            int diff=pre[to]-pre[from];
            if(diff!=to-from) ans[i]=false;
        }
    return ans;
    }
};
