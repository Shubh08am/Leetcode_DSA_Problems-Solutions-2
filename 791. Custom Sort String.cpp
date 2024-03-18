class Solution {
public:
    string customSortString(string order, string s) {
        vector<pair<int,char>>pos; 
        int n=order.size();
        for(int i=0;i<n;i++) pos.push_back({i,order[i]}) ;
        sort(pos.begin(),pos.end()); 
        unordered_map<char,int>freq; 
        for(auto&ch:s) freq[ch]++; 
        string res;
        for(auto&[occ,ch]:pos){
                int appear = freq[ch]; 
                while(appear--) res+=ch;
                freq[ch]=0;
        }
        for(auto&it:freq){
            int appear = it.second;
            while(appear--) res+=it.first;
        }
    return res;
    }
};
