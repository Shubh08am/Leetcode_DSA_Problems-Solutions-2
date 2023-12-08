class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size() , time = 0 ; 
        for(int i=0;i<n-1;i++){
            int diff_1 = points[i][0] - points[i+1][0] ;
            int diff_2 = points[i][1] - points[i+1][1] ;
            time+=max(abs(diff_1),abs(diff_2)) ;
        }
        return time; 
    }
};
