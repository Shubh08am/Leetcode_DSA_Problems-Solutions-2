class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int n=word.size(),i=k,j=0,c=0; 
        string s=word.substr(0,k); 
        while(i<n){
            //first k remove 
            string ss = word.substr(i,n-i) ;
            string sss = word.substr(0,n-i) ; 
            if(sss==ss) return c+1;
            c++;
            i=i+k;
        }
        return c+1;
    }
};
