class Solution {
public:
    int countTestedDevices(vector<int>& nums) {
        int n=nums.size(),a=0;
        for(int i=0;i<n;i++){
            int ok=0;
            if(nums[i]==0) continue;
            a++;
            for(int j=i+1;j<n;j++){
                 if(nums[j]==0) continue;
                nums[j]=max(nums[j]-1,0);
                ok++;
            }
           // a+=(ok>0);
        }
      //  a+=(nums[n-1]>0);
        return a;
    }
};
