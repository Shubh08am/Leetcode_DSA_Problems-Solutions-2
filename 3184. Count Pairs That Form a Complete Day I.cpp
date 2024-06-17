class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long ans=0; 
        map<int,int>freq; 
        //12 12 6 0 0 
        //12 -> 1 
        //12 -> 2 , ans = 1 
        //0 -> 2 , ans = 2 
        for(auto&it:hours){
            it%=24;
           // cout << it << " " << freq[it] << "\n";
            ans+=freq[it];
            freq[(24-it)%24]++;
        }
        return ans;
    }
};
