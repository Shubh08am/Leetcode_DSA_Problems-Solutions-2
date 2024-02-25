class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        	map<int,int>m;
	for(auto i : nums) m[i]++;
	for(auto&[x,y]:m) if(y>2) return 0;
	return 1;
    }
};
