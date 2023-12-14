class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
      map<int,int>mp;
for(auto&it:arr) mp[it]++;
int n=arr.size();
for(auto&it:mp){
	if(it.second>n/4) return it.first;
}
return -1;  
    }
};
