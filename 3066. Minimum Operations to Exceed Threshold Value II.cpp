#define ll long long
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        multiset<ll>ms(nums.begin(),nums.end()); 
        int op=0;
        while(*(ms.begin())<k && ms.size()>1){
            ll val1 = *(ms.begin()) ; 
            ms.erase(ms.find(val1));
            ll val2 = *(ms.begin()) ; 
            ms.erase(ms.find(val2));
            ms.insert(2ll*val1+val2);
            op++;
        }
        return op;
    }
};
