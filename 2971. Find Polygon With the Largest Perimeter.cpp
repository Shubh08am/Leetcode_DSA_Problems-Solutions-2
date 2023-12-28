#define ll long long
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        ll n=nums.size(),a=-1; 
        sort(nums.begin(),nums.end()) ; 
        vector<ll>p ; 
        for(auto i : nums) p.push_back(i) ; 
        for(ll i=1;i<n;i++) p[i]+=p[i-1] ; 
        ll i=1,c=p[1]; 
        while(i<n-1){
            if(p[i]>nums[i+1]){
                c=p[i+1];
                a=c;
            }
            else{
                c=p[i+1];
            }
            i++;
        }
        return a;
    }
};
