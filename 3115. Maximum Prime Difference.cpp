class Solution {
public:
    bool isPrime(int n){
        for(int i=2;i<=n/2;i++){
            if(n%i==0) return 0;
        } 
    return n==1?0:1;
    }
    int maximumPrimeDifference(vector<int>& nums) {
        int diff=0,n=nums.size(); 
        for(int i=0;i<n;i++){
            if(isPrime(nums[i])){
                diff=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(isPrime(nums[i])){
                diff=abs(i-diff);
                break;
            }
        }
    return diff;
    }
};
