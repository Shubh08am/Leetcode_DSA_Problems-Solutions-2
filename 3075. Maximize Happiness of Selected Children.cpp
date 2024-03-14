class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
       	long long sum = 0;
	int start = 0;
	priority_queue<long long>pq;
	for(auto&it:happiness) pq.push(it);
	while(k--&&!pq.empty()){ 
        if(pq.top()<start) continue;
		sum+=pq.top()-start;
		start++;
		pq.pop();
	}
	return sum; 
    }
};
