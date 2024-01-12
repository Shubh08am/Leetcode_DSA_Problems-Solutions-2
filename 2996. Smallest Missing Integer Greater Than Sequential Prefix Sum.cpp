class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size(),ans=1e9; 
        set<int>s(nums.begin(),nums.end()); 
        int i=1,st=nums[0];
        
        while(i<n){
            if(nums[i]-nums[i-1]==1){
                st+=nums[i];
                i++;
                continue;
            }
            break;
        }
        while(s.count(st)) st++;
      return st;
    }
};
