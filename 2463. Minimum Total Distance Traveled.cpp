#define ll long long
class Solution {
public:
    ll solve(int currPosOfRobot, int currPosOfFactory, int currLimitOfFactory , vector<int>& robot, vector<vector<int>>& factory,vector<vector<vector<ll>>>&dp,int n,int m) {
        if(currPosOfRobot==n) return 0; 
        if((currPosOfFactory==m && currPosOfRobot<n) || currLimitOfFactory<0) return 1e15;
        
        ll &val = dp[currPosOfRobot][currPosOfFactory][currLimitOfFactory]; 
        
        if(val!=-1) return val ;
        val=0; 
        
        ll take = 1e15 ; 
        if(currLimitOfFactory>0) take = abs(robot[currPosOfRobot]-factory[currPosOfFactory][0])+solve(currPosOfRobot+1,currPosOfFactory,currLimitOfFactory-1,robot,factory,dp,n,m);
        
        ll notTake = 1e15 ; 
         if(currPosOfFactory+1<m) notTake = solve(currPosOfRobot,currPosOfFactory+1,factory[currPosOfFactory+1][1],robot,factory,dp,n,m); 
       
        
    return val = min(take,notTake);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int n = robot.size() , m = factory.size() , l = 0; 
        for(auto&it: factory) l = max(l,it[1]); 
        vector<vector<vector<ll>>>dp(101,vector<vector<ll>>(101,vector<ll>(101,-1))) ; 
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        return solve(0,0,factory[0][1],robot,factory,dp,n,m);
    }
};
