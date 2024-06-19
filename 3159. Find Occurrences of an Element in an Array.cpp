class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        map<pair<int,int>,int>mp; 
        int n=nums.size(),occ=1;
        for(int i=0;i<n;i++){
            if(nums[i]==x){
                mp[{occ,x}]=i;
                occ++;
            }
        }
        vector<int>ans;
        for(auto&it:queries){
            int occ=it; 
            if(mp.find({it,x})!=mp.end()) ans.push_back(mp[{it,x}]); 
            else ans.push_back(-1);
        }
    return ans;
    }
};
