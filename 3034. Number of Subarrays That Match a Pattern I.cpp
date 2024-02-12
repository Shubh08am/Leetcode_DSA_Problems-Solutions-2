class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& p) {
        int n = nums.size() , m=p.size() ; 
        int diff = n-m ; 
        long res=0; 
        for(int i=0;i<diff;i++){
            int ok=0;
            for(int j=0;j<m;j++){
                if(p[j]==1 && nums[i+j]>=nums[i+j+1]){
                    ok=1;
                    break;
                }
                if(p[j]==-1 && nums[i+j+1]>=nums[i+j]){
                    ok=1;
                    break;
                }
                if(p[j]==0 && nums[i+j]!=nums[i+j+1]){
                    ok=1;
                    break;
                }
            }
            res+=(ok==0);
        }
        return res; 
    }
};
