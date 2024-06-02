class Solution {
public:
    const int mod=1e9+7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        //k*n dp will tle 
        //think greedy -> [efficiency,speed] -> sort on the basis of efficiency 
        //and always try to take max efficiency and remove least speed i.e maxHeap and minHeap 
        
        long long max_performance=0; 
        priority_queue<pair<long long,long long>>efficiencyperf ; 
        for(int i=0;i<n;i++){
            efficiencyperf.push({efficiency[i],speed[i]});
        }
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>speedPerf ; 
        long long speed_sum=0;
        while(!efficiencyperf.empty()){
            auto team = efficiencyperf.top();
            efficiencyperf.pop(); 
            long long curr_efficiency=team.first;
            long long curr_speed = team.second;
            speedPerf.push({curr_speed,curr_efficiency});
            speed_sum=(1ll*speed_sum+1ll*curr_speed); 
            
            if(speedPerf.size()>k){
                //cout << speed_sum << " " << speedPerf.top().first << "\n";
                speed_sum=((1ll*speed_sum-1ll*speedPerf.top().first));
                speedPerf.pop();
            }
            
            //not necessary to have k -> atmost k 
            max_performance=(max(1ll*max_performance,(1ll*speed_sum*curr_efficiency)));
        }
    return max_performance%mod;
    }
};
