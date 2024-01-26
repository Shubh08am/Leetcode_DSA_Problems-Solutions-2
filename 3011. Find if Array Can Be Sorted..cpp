class Solution {
public:
    int setBit(int number){
        int cntSetBit=0;
        while(number){
            cntSetBit+=(number&1);
            number>>=1;
        }
    return cntSetBit;
    }
    bool canSortArray(vector<int>& nums) {
       int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                int set_a = setBit(nums[j-1]);
                int set_b = setBit(nums[j]);
                if(set_a==set_b && nums[j-1]>nums[j]) swap(nums[j-1],nums[j]);
            }
        }
    return is_sorted(nums.begin(),nums.end());
    }
};
