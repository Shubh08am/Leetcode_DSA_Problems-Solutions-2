class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
       int curr_sum=1,n=coins.size(),i=0;
       sort(coins.begin(),coins.end());
        while(i<n && curr_sum>=coins[i]) {
                curr_sum+=coins[i];
                i++;
        } 
    return curr_sum;
    }
};
