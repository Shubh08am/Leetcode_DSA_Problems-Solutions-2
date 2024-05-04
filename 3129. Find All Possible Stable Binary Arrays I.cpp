int dp[201][201][201][2]; 
const int mod=1e9+7;
class Solution {
public:
    int solve(int zero, int one, int limit,int type,int same){
        if(same>limit) return 0;
        if(zero==0 && one==0) return 1; 
        int &val= dp[zero][one][same][type]; 
        int z=0,o=0;
        if(val!=-1) return val;
        
        if(type==0){
            if(zero>0){
                z=solve(zero-1,one,limit,0,same+1); 
            }
            if(one>0){
                o=solve(zero,one-1,limit,1,1);
            }
        }
        else if(type==1){
            if(zero>0){
                z=solve(zero-1,one,limit,0, 1); 
            }
            if(one>0){
                o=solve(zero,one-1,limit,1, same+1);
            }
        }
    return val=(z+o)%mod;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp,-1,sizeof(dp)); 
        return (solve(zero-1,one,limit,0,1) + solve(zero,one-1,limit,1,1)) %mod ; 
    }
};
