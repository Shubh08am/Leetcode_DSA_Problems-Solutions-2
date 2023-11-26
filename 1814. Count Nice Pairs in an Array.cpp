class Solution {
public:
    const int mod = 1e9+7;
    int countNicePairs(vector<int>& nums) {
        /*
        nums[i] - rev(nums[i]) == nums[j] + rev(nums[j])
        13,10,35,24,76
        13-31 = -18 
        10-1=9
        35-53 = -18 [13,35]
        24-42 = -18 [13,24] , [35,24]
        76-67=9 [10,76]  

        42,11,1,97
        42-24=18
        11-11=0
        1-1=0 [11,1]
        97-79=18 [42,79]
        */

        map<int,int>freq;
        int ans=0;
        for(auto&it:nums){
            string rev = to_string(it);
            reverse(rev.begin(),rev.end());
            int rev_it = stoi(rev);
            ans=(1ll*(ans+freq[it-rev_it]))%mod;
            freq[it-rev_it]++;
        }
    return ans;    
    }
};
