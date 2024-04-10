class Solution {
public:
 // vector<vector<vector<int>>>dp ; 
    unordered_map<string,int>dp ; 
    int solve(int ind,int len,int sum,vector<int>&nums){
        if(sum<0 || len<0 ) return 0; 
        if(ind==nums.size()) return (sum==0 && len==0) ?1:0;
        
        string key = to_string(ind) + "-" +  to_string(len)+ "-" +  to_string(sum); 
        if(dp.find(key)!=dp.end()) return dp[key] ; 
        
        return dp[key] = solve(ind+1,len-1,sum-nums[ind],nums) || solve(ind+1,len,sum,nums) ; 
    }
    bool splitArraySameAverage(vector<int>& nums) {
        int n=nums.size(); 
        int sum = accumulate(nums.begin(),nums.end(),0); 
    //  dp.resize(n,vector<vector<int>>(n,vector<int>(sum+1,-1)));
        for(int i=1;i<n;i++){
            int curr_sum = (sum*i) ; 
            if(curr_sum%n==0){
                if(solve(0,i,curr_sum/n,nums)) return true;
            }
        }
    return false;
    }
};
