class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=0;
        for(auto&val:nums){
            if((val+ans)%2==0){
                ans++;
            }
        }
        return ans;
    }
};
