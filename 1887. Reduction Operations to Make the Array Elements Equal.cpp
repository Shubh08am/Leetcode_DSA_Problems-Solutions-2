class Solution {
public:
    int reductionOperations2(vector<int>& nums) {
        map<int,int>freq;
        for(auto it : nums) freq[it]++;
        vector<int>v;
        for(auto&it:freq) v.push_back(it.first);
        reverse(v.begin(),v.end()); 
        int ans=0;
        int n=v.size();
        for(int i=0;i<n-1;i++){
            freq[v[i+1]]+=freq[v[i]];
            ans+=freq[v[i]];
            freq[v[i]]=0;
        }
    return ans;
    }
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end()); 
        int ans=0, n=nums.size() ,i=0,cnt=0;
        while(i<n-1){
            if(nums[i]!=nums[i+1]){
                cnt++;
            }
            ans+=cnt;
            i++;
        }
    return ans;
    }
};
