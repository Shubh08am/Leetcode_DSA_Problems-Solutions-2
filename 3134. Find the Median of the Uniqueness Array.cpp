#define ll long long
class Solution {
public:
    ll isPossible(ll mid,ll curr,vector<int>&nums,ll n){
        ll unique=0; 
        ll i=0,j=0; 
        unordered_map<ll,ll>freq;
        
        while(j<n){
            freq[nums[j]]++; 
            ll sz = freq.size(); 
            
           // more than mid -> remove cal for i 
            if(freq.size()>mid){
                while(freq.size() > mid){
                    --freq[nums[i]]; 
                    if(freq[nums[i]]==0) freq.erase(nums[i]);
                    i++;
                }
            }
            ll window = j-i+1;
            unique+=(window);
            j++;
        }
        return curr>unique ;
    }
    int medianOfUniquenessArray(vector<int>& nums) {
        //find unique and than use binary search 
        //nlogn 
        unordered_map<int,int>mp; 
        for(auto i : nums) mp[i]++;
        ll n=nums.size() ; 
        ll curr ; 
     
  //      if(n&1) curr=nums[n/2] ; 
  //      else curr = min(nums[n/2],nums[n/2-1]); 
        
        //total median possible 
       ll total = (1ll*n*(n+1))/2;
       curr =  ceil(1.0*total/2.0) ; 
        
        ll start=1,end=mp.size();
        while(start<end){
            ll mid = start+(end-start)/2; 
            if(isPossible(mid,curr,nums,n)){
                start=mid+1;
            }
            else{
                end=mid;
            }
        }
        return start;
    }
};
