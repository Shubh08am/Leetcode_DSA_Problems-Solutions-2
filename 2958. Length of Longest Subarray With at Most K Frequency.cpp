class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int a=0;
        map<int,int>mp; 
        int n=nums.size(),j=0,i=0;
        while(j<n){
            mp[nums[j]]++;
            while(mp[nums[j]]>k){
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
              //   if(mp[nums[i]]<=k) a=max(a,j-i+1);
                i++;
            }
           if(mp[nums[j]]<=k) a=max(a,j-i+1);
            j++;
        }
        return a;
    }
};
