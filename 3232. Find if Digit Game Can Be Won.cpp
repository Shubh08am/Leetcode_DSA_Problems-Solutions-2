class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int a=0,b=0,c=0;
        for(auto&i:nums){
            string s=to_string(i); 
            if(s.size()==1) a+=i;
            else b+=i;
            c+=i;
        }
        c=c-max(a,b);
        return max(a,b) > c ; 
    }
};
