class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        map<int,int>mp;
        int n=nums.size(),ans=0;
        sort(nums.begin(),nums.end()); 
        for(int i=0;i<n;i++){
             //either increase it or not 
            mp[nums[i]+1]=max(mp[nums[i]+1],mp[nums[i]]+1);
            mp[nums[i]]=max(mp[nums[i]],mp[nums[i]-1]+1);
            ans=max({ans,mp[nums[i]],mp[nums[i]+1]});
        }
    return ans;
    }
};
