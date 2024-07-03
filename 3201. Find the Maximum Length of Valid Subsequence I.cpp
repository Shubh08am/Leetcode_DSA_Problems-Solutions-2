class Solution {
public:
    int maximumLength(vector<int>& nums) {
        //all even cases 
int even=0;
for(auto&it:nums) even+=(it%2==0);

//all odd cases 
int odd=0;
for(auto&it:nums) odd+=(it%2==1);

//all odd even cases
int oddEven=0;
for(auto&it:nums) 	oddEven+=(oddEven%2==0?it%2==1:it%2==0);

//all even odd cases
int evenOdd=0;
for(auto&it:nums) 	evenOdd+=(evenOdd%2==1?it%2==1:it%2==0);

int ans = max(max(odd,even),max(oddEven,evenOdd));
        return ans;
    }
};
