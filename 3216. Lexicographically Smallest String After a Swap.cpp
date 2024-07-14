class Solution {
public:
    string getSmallestString(string s) {
        string curr(101,'9') ; 
        string a=s; 
        int n=s.length(); 
        for(int i=0;i<=n-2;i++){
                int x=(s[i]-'0') , y=(s[i+1]-'0'); 
                if(x%2==y%2){
                    swap(s[i],s[i+1]); 
                    curr=min(curr,s); 
                    swap(s[i],s[i+1]);
            }
        }
        return min(curr,a);
    }
};
