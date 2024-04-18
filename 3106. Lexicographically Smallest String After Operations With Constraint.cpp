class Solution {
public:
    string getSmallestString(string s, int k) {
        int n = s.length(),i=0;
        string a= "";
        
        while(i<n && k>0){
            if(s[i]=='a') a+='a';
            
            else{
                int b = s[i]-'a' , c = 'z'-s[i]+1 , d = min(b,c);
                
                if(d<=k){
                    a+=('a');
                    k-=d;
                }
                else{
                    char ch = s[i]-k;
                    k=0;
                    a+=(ch);
                }
            }
            i++;
        }
        while(i<n) a+=s[i++];
        return a;
    }
};
