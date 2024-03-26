class Solution {
public:
    int maximumLengthSubstring(string s) {
        int a=0,n=s.size(); 
        for(int i=0;i<n;i++){
            map<int,int>m; 
            for(int j=i;j<n;j++){
                m[s[j]]++;
                if(m[s[j]]==3) break; 
                a=max(a,j-i+1);
            }
        }
        return a;
    }
};
