class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int n=nums.size(),diff=0,b=1,i=2; 
        int c = nums[0]+nums[1] ; 
        while(i<n-1){
            int a = nums[i]+nums[i+1];
            if(a==c) b++;
            else break;
            i+=2;
        }
        return b;

    }
};
