class Solution {
public:
    long long minOper(int n,vector<int>& nums, vector<int>& target,vector<long long>&diff){
        long long a = 0, b = 0,c=0,i=0;
          while(i < n){
            if(nums[i] < target[i]){
                long long curr_diff = diff[i];
                if(a < curr_diff){
                    c+= curr_diff - a;
                }
                a=curr_diff;
                b=0;
            //   cout<<a<<" "<<b<<"\n";

            }
            else if(nums[i] > target[i]){
                long long curr_diff = -diff[i];
                if(b < curr_diff){
                    c+= curr_diff - b;
                }
                b=curr_diff;
                a=0;
             //   cout<<a<<" "<<b<<"\n";
            }
            else if(nums[i] == target[i]){
                a = 0;
                b = 0;
            //   cout<<a<<" "<<b<<"\n";
            }
            i++;
        }
        return c;
    }
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        vector<long long>diff(n);
        for(int i=0;i<n;i++) diff[i]=target[i]-nums[i]; 
        return minOper(n,nums,target,diff);
      
    }
};
