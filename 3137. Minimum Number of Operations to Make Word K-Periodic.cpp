class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string,int>freq; 
        int occ=0,n=word.size();
        for(int i=0;i<=n-k;i+=k) {
            //see string of size k 
            freq[word.substr(i,k)]++;
        }
        for(auto& it: freq) occ=max(occ,it.second);
        return n/k==occ?0:n/k-occ;
        
    }
};
