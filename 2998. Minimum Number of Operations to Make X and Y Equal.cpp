class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
     //  return solve(x,y); 
        queue<pair<int,int>>pq; 
        unordered_map<int,int>mp; 
        pq.push({x,0});
        mp[0]=1;
        while(!pq.empty()){
            int a = pq.front().first,b=pq.front().second; 
            pq.pop();
            if(a==y) return b;
            
            if(mp[a+1]==0){
                mp[a+1]++;
                pq.push({a+1,b+1});
            }
            if(mp[a-1]==0){
                mp[a-1]++;
                pq.push({a-1,b+1});
            }
            if(a%11==0 and mp[a/11]==0){
                mp[a/11]++;
                pq.push({a/11,b+1});
            }
            if(a%5==0 and mp[a/5]==0){
                mp[a/5]++;
                pq.push({a/5,b+1});
            }
        }
    return -1;
    }
};
