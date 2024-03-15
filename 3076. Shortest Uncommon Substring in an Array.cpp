class Solution {
public:
    void allSubstring(multiset<string>&s,string&word){
        int n=word.size(); 
        for(int i=0;i<n;i++){
            string curr = "" ; 
            for(int j=i;j<n;j++){
                curr+=word[j];
                s.insert(curr);
            }
        }
    }
    vector<string> shortestSubstrings(vector<string>& arr) {
        multiset<string>s; 
        for(string word:arr) allSubstring(s,word); 
        
        vector<string>ans; 
        for(auto&word:arr){
            vector<string>possible; 
            multiset<string>removed; 
            int n=word.size(); 
            for(int i=0;i<word.size();i++){ string ss="";
                for(int j=i;j<n;j++) {ss+=word[j]; s.erase(s.find(ss)); removed.insert(ss);}
            }
            for(auto&it:removed){
                if(!s.count(it)) possible.push_back(it);
            }
            for(auto&it:removed){
                s.insert(it);
            }
            sort(possible.begin(),possible.end(),[&](string &a,string &b){
                if(a.size()==b.size()) return a<b;
                else return a.size()<b.size();
            });
            if(possible.size()>0) ans.push_back(possible[0]);
            else ans.push_back("");
        } 
    return ans;
    }
};
