class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int even=0;
        for(auto&it:nums){
            even+=(it%2==0);
        }
        return even>=2;
    }
};
