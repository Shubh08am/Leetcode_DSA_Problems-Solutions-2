class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long>prefix; 
        for(auto&val:nums) prefix.push_back(val); 
        for(int i=1;i<n;i++) prefix[i]+=prefix[i-1];
        long long max_sum=-1e15,curr_sum=0; 
        unordered_map<int,int>pos; 
        for(int i=0;i<n;i++){
            int left_sum_1 = (nums[i]-k) ; 
            int left_sum_2 = (nums[i]+k) ; 
            if(pos.find(left_sum_1)!=pos.end()){
                int till_where = pos[left_sum_1];
                curr_sum = prefix[i]-(till_where>0?prefix[till_where-1]:0);
                max_sum=max(max_sum,curr_sum);
            }
            if(pos.find(left_sum_2)!=pos.end()){
                int till_where = pos[left_sum_2];
                curr_sum = prefix[i]-(till_where>0?prefix[till_where-1]:0);
                max_sum=max(max_sum,curr_sum);
            }
            if(pos.find(nums[i])==pos.end()) pos[nums[i]]=i;
            else if(pos.find(nums[i])!=pos.end()){
                //take max prefix sum one 
                long long sum1 = prefix[i] ; 
                long long sum2 = prefix[pos[nums[i]]] ;
                if(sum2>sum1) pos[nums[i]]=i;
            }
        }
    return max_sum==-1e15?0:max_sum;
    }
};

