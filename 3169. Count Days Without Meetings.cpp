class Solution {
public:
    int countDays(int days, vector<vector<int>>& intervals) {
        vector<vector<int>>merged; 
        sort(intervals.begin(),intervals.end());
        merged.push_back(intervals[0]);
        int n=intervals.size(),a=0;
        for(int i=1;i<n;i++){
            if(merged.back()[1]>=intervals[i][0]){
                merged.back()[1]=max(merged.back()[1],intervals[i][1]);
            }
            else{
                merged.push_back(intervals[i]);
            }
        }
        for(int i=0;i<merged.size();i++){
            days-=(merged[i][1]-merged[i][0]);
            days--;
        }
        return days;
    }
};
