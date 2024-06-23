class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();        
        int i = 0;
        int ans = 0;
        while(i<n){
            if(nums[i]==0){
                if(i+2>=n) return -1;
                ans++; 
                nums[i]^=1; nums[i+1]^=1; nums[i+2]^=1;
                i++;
            } 
            else if(i+1<n && nums[i+1]==0){
                if(i+3>=n) return -1;
                ans++; 
                nums[i+1]^=1; nums[i+2]^=1; nums[i+3]^=1;
                i++;
            }
            else if(i+2<n && nums[i+2]==0){
                if(i+4>=n) return -1;
                ans++; 
                nums[i+2]^=1; nums[i+3]^=1; nums[i+4]^=1;
                i++;
            }
            else i++;
        }
        if(count(nums.begin(),nums.end(),1)!=n) return -1;
        return ans;
    }
};
