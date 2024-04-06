#define ll long long
class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        ll cnt=1,a=0,n=nums.size(); 
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]) cnt++;
            else {
                a+= (1ll*cnt*(cnt+1)) / 2ll ; 
                cnt=1;
            }
        }
        a+= (1ll*cnt*(cnt+1)) / 2ll ; 
        return a;
    }
};
