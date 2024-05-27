class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        map<int,int>mp; 
        int x=0;
        for(auto i: nums) mp[i]++;
        for(auto&i:mp){
            if(i.second==2) x^=i.first;
        }
        return x;
    }
};
