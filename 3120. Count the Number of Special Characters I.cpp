class Solution {
public:
    int numberOfSpecialChars(string w) {
        int n=w.size();
        string s,ss; map<char,int>m;int a=0; set<char>s1;
        for(auto i : w) {
            if(i>='a' && i<='z') m[i]++;
            else s1.insert(i);
        } 
        for(auto i : s1) ss+=i;
            transform(ss.begin(), ss.end(), ss.begin(), ::tolower); 
     for(auto i : ss) {
         if(m[i]>0) a++;
     }
        return a;
    }
};
