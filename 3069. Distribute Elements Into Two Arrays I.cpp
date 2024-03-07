class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>a,b,c; 
        for(auto&it:nums){
            if(a.size()==0) a.push_back(it);
            else if(b.size()==0) b.push_back(it);
            else{
                if(a.back()>b.back()) a.push_back(it);
                else if(a.back()<=b.back()) b.push_back(it);
            }
        } 
        for(auto&it:a) c.push_back(it);
        for(auto&it:b) c.push_back(it);
    return c;
    }
};
