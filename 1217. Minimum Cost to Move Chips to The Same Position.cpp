class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
    sort(arr.begin(),arr.end());
	int prev = 1,n=arr.size();
	for(int i=1;i<n;i++){
		int curr = arr[i];
		int diff = curr-prev;
		if(diff<=1){
			prev=arr[i];
		}
		else{
			prev++;
		}
	}
return prev; 
    }
};
