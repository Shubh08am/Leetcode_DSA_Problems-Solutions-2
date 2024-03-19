class Solution {
public:
    string minimizeStringValue(string s) {
        int n=s.size(); 
        string a;
        unordered_map<char,int>freq; 
       for(auto &i  : s) freq[i]++;
        string b ; 

        for(auto&i:s){
            if(i=='?'){
                 char less = 'a' ; 
                for(char ch='a';ch<='z';ch++){
                    if(freq[less] > freq[ch]){less=ch;}
                }   b+=less;
                    freq[less]++;
            }
        }
        sort(b.begin(),b.end()) ; 
        int o=0; 
        for(int i=0;i<n;i++){
            if(s[i]=='?') s[i] = b[o++];
        }
       return s ;
    }
};
//"?aa?b???c"
//"daaebfghc"

//"abcdefghijklmnopqrstuvwxy??" 
//"abcdefghijklmnopqrstuvwxyaz"
//"?aa?b???c"
//"daaebfghc"

//"abcdefghijklmnopqrstuvwxy??" 
//"abcdefghijklmnopqrstuvwxyaz"
