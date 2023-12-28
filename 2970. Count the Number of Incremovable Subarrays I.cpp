#define ll long long
class Solution {
public:
    bool inc(vector<int>&a){
        int n = a.size();
        for(int i=0;i<n-1;i++){
            if(a[i]>=a[i+1]) return 0;
        }
    return 1;
    }
    int incremovableSubarrayCount(vector<int>& nums) {
        ll n=nums.size() , a=0; 
        for(ll i=0;i<n;i++){
            for(ll j=i;j<n;j++){
                vector<int>left(nums.begin(),nums.begin()+i) ; 
                ll k=j+1; 
                while(k<n) left.push_back(nums[k++]);
                a+=inc(left);
            }
        }
    return a;
    }
};
