class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.rbegin(),capacity.rend());
int total = accumulate(apple.begin(),apple.end(),0);
int cnt = 0;
for(auto&it:capacity){
	total-=it;
	if(total<=0) break;
	cnt++;
}
 return cnt+1;
    }
};
