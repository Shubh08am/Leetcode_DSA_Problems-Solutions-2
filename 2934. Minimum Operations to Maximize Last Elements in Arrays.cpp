class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2) {
         int n=nums1.size(),c=0,d=0,e=0;
        // swap from 1 to 2 and 2 to 1
        for(int i=0;i<n-1;i++){
            if(nums1[i]<=nums1[n-1] and nums2[n-1]>=nums2[i]) {
                continue;
            }
            if(nums1[i]<=nums2[n-1] and nums1[n-1]>=nums2[i]) c++;
            else{
                c=1e9;
                break;
            }
        }
    return c;
    }
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),c=0,d=0,e=0;
        int a = *max_element(nums1.begin(),nums1.end()); 
        int b = *max_element(nums2.begin(),nums2.end()); 
        if(a==nums1[n-1] && b==nums2[n-1]) return 0;
        
        c = solve(nums1,nums2) ; // swap from 1 to 2
        swap(nums2[n-1],nums1[n-1]);
        d = 1 + solve(nums1,nums2) ; //// swap from 2 to 1 
        e = min(c,d);
        return e==1e9?-1:e;
        
    }
};
