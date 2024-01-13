class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans=0; 
        for(auto&it:nums) ans^=it;
        int req = (ans^k) , step=0;
        while(req>0){
            step+=(req&1);
            req/=2;
        }
    return step;
    }
};
