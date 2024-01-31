#define ll long long 
class Solution {
public:
    long long flowerGame(int n, int m) {
        ll mini = min(n,m) , maxi=max(n,m);
        //odd even think 
        long long a= 1ll*n ; 
        long long b= 1ll*m ; 
        ll ans = (1ll*n*m)/2 ;
        return ans;
    }
};
