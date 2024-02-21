class Solution {
public:
    bool ok(string&s1,string&s2){
        int n=s1.size(),m=s2.size(); 
        if(n>m) return 0; 
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]) return 0;
        }
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[m-n+i]) return 0;
        }
                   

        return 1;
    }
    int countPrefixSuffixPairs(vector<string>& w) {
        int n=w.size(),a=0; 
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
               if(ok(w[i],w[j])) a++; 
            }
        }
    return a;
    }
};
