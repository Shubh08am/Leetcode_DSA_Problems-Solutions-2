#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        ordered_set a,b; 
        vector<int>v1,v2,result; 
        int n=nums.size();
        a.insert(-nums[0]);
        b.insert(-nums[1]);
        v1.push_back(nums[0]);
        v2.push_back(nums[1]);

        for(int i=2;i<n;i++){
            int val = nums[i];
            int cnt_a = a.order_of_key(-val);
            int cnt_b = b.order_of_key(-val);
            
            if(cnt_a > cnt_b){
                 v1.push_back(val);
                 a.insert(-val);
            }
            else if(cnt_a<cnt_b){
                v2.push_back(val);
                b.insert(-val);
            }
            else if(cnt_a==cnt_b){
                //in b
                if(a.size()>b.size()){
                    v2.push_back(val);
                    b.insert(-val);
                }
                //in a
                else{
                    v1.push_back(val);
                    a.insert(-val);
                }
            }
        }
        for(auto&val:v1) result.push_back(val);
        for(auto&val:v2) result.push_back(val);

    return result;
    }
};
