class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int n=s.size(),m=target.size(); 
        if(m>n) return 0;
        map<char,int>freq1,freq2; 
        for(auto&ch:s) freq1[ch]++;
        for(auto&ch:target) freq2[ch]++;
        int cnt=101;
        for(char ch='a';ch<='z';ch++){
            if(freq2[ch]>0){
                if(freq1[ch]==0) return 0;
                int should = freq2[ch] ; 
                if(freq1[ch]>=freq2[ch]){
                    cnt=min(cnt,freq1[ch]/should);
                 }
                else return 0;
            }
        }
        return cnt==101?0:cnt;
    }
};
