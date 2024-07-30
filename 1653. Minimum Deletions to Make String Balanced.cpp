class Solution {
public:
    int solve(int ind,int b,int n,string& s,vector<vector<int>>& dp){
        if(ind==n) return 0; 
        if(dp[ind][b]!=-1) return dp[ind][b]; 
        int operation=n; 
        
        if(s[ind]=='a'){
            if(b==1){
                operation=1+solve(ind+1,1,n,s,dp);
            }
            else{
                 operation=solve(ind+1,0,n,s,dp);
            }
        }
        else{
            if(b==1) operation=solve(ind+1,1,n,s,dp);
            else operation=min(1+solve(ind+1,0,n,s,dp),solve(ind+1,1,n,s,dp));
        }
        return dp[ind][b]=operation;
    }
    int minimumDeletions(string s) {
       int n=s.size(); 
    //   vector<vector<int>>dp(n,vector<int>(2,-1)); 
   //    return solve(0,0,n,s,dp); 
        stack<char>st;
        int operation=0;
        for(int i=0;i<n;i++){
            if(!st.empty() && st.top()=='b' && s[i]=='a') {st.pop(); operation++;}
            else st.push(s[i]);
        }
        return operation;
    }
};
