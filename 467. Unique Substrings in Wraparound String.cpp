class Solution {
public:
    int findSubstringInWraproundString(string s) {
        //cac -> c a ca cac [subtring of s] 
        //but only continuous is c and a -> in base -> ans=2 
        vector<int>freq(26,0); 
        //if consecutive character increase the frequency 
        int len=1,n=s.size();
        freq[s[0]-'a']=1; 
        for(int i=1;i<n;i++){
            if(s[i]-s[i-1]==1 || (s[i]=='a' && s[i-1]=='z')){
                ++len;
                freq[s[i]-'a']=max(len,freq[s[i]-'a']);
            }
            else{
                len=1;
                freq[s[i]-'a']=max(len,freq[s[i]-'a']);
            }
        }
    int ans = accumulate(freq.begin(),freq.end(),0) ;
    return ans;
    }
};
