class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
       /* int n = nums1.size() ; 
        map<int,int>m2 ; 
        for(auto i : nums2) m2[i]++; 
        
        for(int x=-1000;x<=1000;x++){
                    map<int,int>m1; 
                    for(auto it : nums1){
                        m1[it+x]++;
                    }
            if(m1==m2) return x;
        }*/
        sort(nums1.begin(),nums1.end()) ; 
                sort(nums2.begin(),nums2.end()) ; 

        return nums2[0]-nums1[0];
    }
};
