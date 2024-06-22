class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        //extra space -> easy 
        //think constant 
        int n=nums.size();
        /*
        use property of expressing 2 no in one no.. 
        if x & y are two no than 
        z = x + n*y 
        than later on x can be obtained by z%n and y by z/n 
        */
        
        //store z first using x (nums[i]) & y (nums[nums[i]]%n) , %n because it may have been modified so used original nums[i]
        for(int i=0;i<n;i++){
            nums[i]=nums[i]+(nums[nums[i]]%n)*n;
        }
        for(int i=0;i<n;i++){
            nums[i]/=n;
        }
        return nums;
    }
};
