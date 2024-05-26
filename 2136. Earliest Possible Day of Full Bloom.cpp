class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        //think -> greedy 
        //plant first the flower which requires more growing time 
        int n=plantTime.size();
        vector<vector<int>>all(n); 
        for(int i=0;i<n;i++){
                all[i]={-growTime[i],plantTime[i]};
        }
        sort(all.begin(),all.end());
        int earliest=0,totalPlantTime=0; 

        for(int i=0;i<n;i++){
            totalPlantTime+=all[i][1]; 
            int currMaxTime=totalPlantTime-all[i][0];
            earliest=max(earliest,currMaxTime);
        }
    return earliest;
    }
};
