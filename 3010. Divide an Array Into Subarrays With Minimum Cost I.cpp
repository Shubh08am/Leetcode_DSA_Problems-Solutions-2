class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n=nums.size(),sum=0,min_sum=1e9;
            for(int j=1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    sum=nums[0]+nums[j]+nums[k];
                    min_sum=min(min_sum,sum);
            }
        }
    return min_sum;
    }
};
