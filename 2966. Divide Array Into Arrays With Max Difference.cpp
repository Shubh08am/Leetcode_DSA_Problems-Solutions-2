class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>>ans,emp;
        int n=nums.size();
        sort(nums.begin(),nums.end()); 
        for(int i=0;i<n-2;i++){
            int start = nums[i] , end = nums[i+2] ; 
            if(end-start>k) return emp;
            else{
                ans.push_back({start,nums[i+1],end});
                i+=2;
            }
        }
        return ans;
    }
};
