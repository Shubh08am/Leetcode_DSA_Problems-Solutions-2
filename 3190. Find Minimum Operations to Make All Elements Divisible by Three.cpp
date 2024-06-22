class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int a=0; 
        for(auto i : nums) a+=i%3>0?1:0;
        return a;
    } 
};
