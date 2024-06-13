class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int prev_pos=-1,n=nums.size(); 
        for(int i=0;i<n;i++){
            if(prev_pos==-1 && nums[i]==1) prev_pos=i; 
            else if(nums[i]==1){
                if(i-prev_pos<=k) return false;
                prev_pos=i;
            }
        }
        return true;
    }
};
