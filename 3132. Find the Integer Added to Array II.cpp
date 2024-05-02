class Solution {
public:
    int solve(int i,int j,vector<int>& nums1, vector<int>& nums2,int n){
        int a=0,b=0,c=0,d=INT_MAX;
        while(b<n){
            if(a==i or a==j){
                a++;
            }
            else{
                if(c==0){
                    d=nums2[b]-nums1[a];
                    c++;
                    a++; 
                    b++;
                }
                else if(nums1[a]+d==nums2[b]){
                    a++ ; 
                    b++;
                }
                else{
                    return INT_MAX;
                }
            }
        }
  return d;
    }
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
         sort(nums1.begin(),nums1.end()) ; 
        sort(nums2.begin(),nums2.end()) ; 
        int n = nums1.size() ,a=INT_MAX; 
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int val = solve(i,j,nums1,nums2,nums2.size());
                a=min(a,val);
            }
        }
        return a;
    }
};
