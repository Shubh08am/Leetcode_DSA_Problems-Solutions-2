#define ll long long
class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        ll n=a.size();
	if (a[n/2] == k){
		return 0;
	}
        
	else if (a[n/2] > k){
		ll ans = 0;
		for (int i = 0; i <= n/2; ++i){
			if (a[i] <= k) continue;
			ans += a[i]-k;
		}
        return ans;
	}
	else{
		ll ans = 0;
		for (int i = n/2; i < n; ++i){
			if (a[i] >= k) continue;
			ans += k-a[i];
		}
        return ans;
	}
    }
};
