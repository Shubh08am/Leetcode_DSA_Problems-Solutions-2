class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int d=0; 
        for(auto&i:nums){
            string s = to_string(i); 
            sort(s.begin(),s.end()) ; 
            char ch = s.back();
            string m(s.size(),ch);
            d+=stoi(m);
        }
        return d;
    }
};
