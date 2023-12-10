class Solution {
public:
    bool ok(char a,char b){
        return a==b || abs(a-b)==1;
    }
    int removeAlmostEqualCharacters(string s) {
         int n = s.length() , ans = 0, i = 0,j=0; 
     while(i<n-1){
         if(ok(s[i],s[i+1])) {ans++;i+=2;}
         else i++;
         
     }
        
 return ans;
    }
};
