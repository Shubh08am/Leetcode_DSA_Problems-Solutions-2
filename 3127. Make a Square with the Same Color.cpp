class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& g) {
        int a=0; 
        a = (g[0][0]=='B')+(g[0][1]=='B')+(g[1][0]=='B')+(g[1][1]=='B') ; 
        if(a>=3) return 1; 
        a = (g[0][0]=='W')+(g[0][1]=='W')+(g[1][0]=='W')+(g[1][1]=='W') ; 
        if(a>=3) return 1; 
        
        a = (g[0][1]=='B')+(g[0][2]=='B')+(g[1][1]=='B')+(g[1][2]=='B') ; 
        if(a>=3) return 1; 
        
        a = (g[0][1]=='W')+(g[0][2]=='W')+(g[1][1]=='W')+(g[1][2]=='W') ; 
        if(a>=3) return 1; 
        
         a = (g[1][0]=='B')+(g[1][1]=='B')+(g[2][0]=='B')+(g[2][1]=='B') ; 
        if(a>=3) return 1; 
        
         a = (g[1][0]=='W')+(g[1][1]=='W')+(g[2][0]=='W')+(g[2][1]=='W') ; 
        if(a>=3) return 1; 
        
        a = (g[1][2]=='B')+(g[1][1]=='B')+(g[2][2]=='B')+(g[2][1]=='B') ; 
        if(a>=3) return 1; 
        
        a = (g[1][2]=='W')+(g[1][1]=='W')+(g[2][2]=='W')+(g[2][1]=='W') ; 
        if(a>=3) return 1; 
        
        return 0;
    }
};