class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        unordered_map<int,int>value; 
        int n=mapping.size(),m=nums.size();
        for(int i=0;i<n;i++){
            value[i]=mapping[i];
        }
        vector<pair<int,int>>allNo;
        for(int i=0;i<m;i++){
            string s = to_string(nums[i]); 
            string new_s; 
            for(auto&ch:s) new_s+=to_string(value[(ch-'0')]);
            int new_no=stoi(new_s);
            allNo.push_back({new_no,i});
        }
        sort(allNo.begin(),allNo.end()); 
        vector<int>ans; 
        for(auto&it:allNo){
            ans.push_back(nums[it.second]);
        }
        return ans;
    }
};
