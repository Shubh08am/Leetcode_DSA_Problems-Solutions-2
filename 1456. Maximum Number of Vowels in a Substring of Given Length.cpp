class Solution {
public:
    bool isVowel(char ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' ; 
    }
    int maxVowels(string s, int k) {
        int n=s.size(),ans=0,i=0,j=0,vow=0;
        while(j<n){
            vow+=isVowel(s[j]);
            if(j-i+1==k){
                ans=max(ans,vow);
                vow-=isVowel(s[i++]);
            }
        j++;
        }
    return ans;
    }
};
