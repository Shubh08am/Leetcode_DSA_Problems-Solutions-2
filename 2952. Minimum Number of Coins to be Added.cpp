class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        //max 2 multiple 
        sort(coins.begin(),coins.end());
        int curr_sum=1,need=0,n=coins.size(),i=0;
        while(curr_sum<=target){
          //  cout<<curr_sum<<" "<<coins[i]<<"\n";
            if(i<n && curr_sum>=coins[i]){
                curr_sum+=coins[i];
                i++;
            }
            else{
                curr_sum<<=1;
                need++;
            }
        }
    return need;
    }
};
