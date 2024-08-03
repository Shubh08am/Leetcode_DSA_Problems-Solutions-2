class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        map<int,int>m1,m2;
for(auto&it:arr) m2[it]++;
for(auto&it:target) m1[it]++;
return m1==m2;
    }
};
