class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        //first condition with prefix and suffix 
        //second condition simple directly 
        int n=nums.size(),beauty=0; 
        vector<int>prefix(n,0),suffix(n,0); 
        prefix[0]=nums[0];
        suffix[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            prefix[i]=max(prefix[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            suffix[i]=min(suffix[i+1],nums[i]);
        }
         /*
          nums   = 1 2 3 4 5 6 
          prefix = 1 2 3 4 5 6 
          suffix = 1 2 3 4 5 6
        */
        for(int i=1;i<n-1;i++){
            int before = prefix[i-1] ; 
            int after = suffix[i+1] ; 
            int current = nums[i] ; 
            if(before<current && current<after){
              //  cout << before << " " << current << " "<<after <<"\n";
                beauty+=2;
            }
            else if(nums[i-1]<current && current<nums[i+1]){
                beauty++;
            }
        }
    return beauty;
    }
};
