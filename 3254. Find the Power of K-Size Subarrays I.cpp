class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size(),flag=1;
       if(k==1) return nums;
        vector<int>ans;
        deque<int>dq; 
        for(int i=0;i<n;i++){
            if(!dq.empty() && !(nums[dq.back()]<nums[i] && nums[i]-nums[dq.back()]==1)){
                flag=0;
            }
            else if(!dq.empty() &&nums[dq.back()]<nums[i] && nums[i]-nums[dq.back()]==1){
                flag++;
            }
            if(i>=k-1){
                if(flag>=k-1 && !dq.empty()){
                    ans.push_back(nums[i]);
                }
                else{
                    ans.push_back(-1);
                }
            dq.pop_front();
            }
            dq.push_back(i);
        }
    return ans;
    }
};
