class Solution {
public:
    bool isVowel(char ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U' ;
    }
    string sortVowels(string A) {
        string s = "" , e= "" ; 
        for(auto&i:A){
            if(isVowel(i)) s+=i;
        }
        int k=0;
        sort(s.begin(),s.end()) ; 
        for(auto&i:A){
            if(isVowel(i)) e+=s[k++];
            else e+=i;
        }
    return e;
    }
};
