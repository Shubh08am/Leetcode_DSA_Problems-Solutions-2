class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        int palindrome=0;
        sort(words.begin(),words.end(),[&](string a,string b){return a.size()<b.size();}); 
        unordered_map<char,int>freq ; 
        for(auto&w:words) for(auto&ch:w) freq[ch]++;
        int totalPairs=0; 
        for(auto&occur:freq)  totalPairs+=occur.second/2; 
        for(auto&w:words){
             totalPairs-=w.size()/2;
             if(totalPairs<0) return palindrome;
             else palindrome++;
        }
        return palindrome;
    }
};
