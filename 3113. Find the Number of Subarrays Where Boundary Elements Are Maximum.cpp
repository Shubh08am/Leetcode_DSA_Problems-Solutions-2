class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        stack<int>s;
long ans = 0;
map<int,int>freq;
for(auto&it:nums){
    while(!s.empty() && s.top()<it){
    	freq[s.top()]--;
    	s.pop();
    }
	ans+=(++freq[it]);
	s.push(it);	
}
return ans;
    }
};
