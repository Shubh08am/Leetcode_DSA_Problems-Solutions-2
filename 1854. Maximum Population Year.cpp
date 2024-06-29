class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        //sweep line || difference array techniques 
        int n=logs.size(); 
        vector<int>prefix(2051,0) ; 
        for(int i=0;i<n;i++){
            int birth=logs[i][0],death=logs[i][1]; 
            prefix[birth]++;prefix[death]--;
        }
        for(int i=1;i<=2050;i++) prefix[i]+=prefix[i-1];
        int maxLive=0,position=0;
        for(int i=0;i<=2050;i++){
            if(prefix[i]>maxLive){
                maxLive=prefix[i]; 
                position=i;
            }
        }
        return position;
    }
};
