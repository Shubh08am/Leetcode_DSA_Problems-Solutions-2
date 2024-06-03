class Solution {
public:
    string clearStars(string s) {
        multiset<pair<char,int>>m; 
        map<int,char>freq;
        string a;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                auto it = *(m.begin());
                m.erase(m.find(it)) ; 
            }
            else m.insert({s[i],-i});
        }
        for(auto&it:m){
            freq[-it.second]=it.first;
        }
        for(auto&it:freq) a+=it.second; 
        return a;
    }
};
