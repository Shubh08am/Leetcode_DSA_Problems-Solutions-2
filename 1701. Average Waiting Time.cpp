class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double avg=0,total_wait=0,last_finished=0; 
        int n = customers.size();
        
        for(int i=0;i<n;i++){
            double arrival = customers[i][0] , time = customers[i][1];
            double curr_arrival = max(last_finished,arrival); 
            double curr_finished = curr_arrival + time ; 
            double curr_wait = curr_finished - arrival ;
            total_wait+=curr_wait;
            last_finished=curr_finished; 
        }
        return (double) total_wait/n ; 
    }
};
