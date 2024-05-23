class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        long long ans = 0; 
string s = to_string(nums[0]); 
int n = s.length();
int m = nums.size();
for(int i=0;i<n;i++){
	//see all differnet character at ith position possible 
	vector<int>freq(10,0);
	for(auto&it:nums){
		freq[((to_string(it))[i]-'0')]++;
	}
	for(int j=0;j<=9;j++){ 
        cout << freq[j]<<" ";
		ans+=(freq[j]*(m-freq[j]));
	}
    cout << ans << " " << "\n";
}
return ans/2;
    }
};
