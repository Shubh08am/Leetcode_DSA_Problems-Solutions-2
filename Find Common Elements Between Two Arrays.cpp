class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>m,mp;int a=0,b=0;
        for(auto i : nums1) m[i]++;
         for(auto i : nums2) mp[i]++;
        
        for(auto i 
: nums1){
            if(mp[i]) a++;
        }
         for(auto i 
: nums2){
            if(m[i]) b++;
        }
        return {a,b};
    }
};
