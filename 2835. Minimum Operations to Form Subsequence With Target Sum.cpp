class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        priority_queue<int>pq(nums.begin(),nums.end()); 
        int step=0; long sum=accumulate(nums.begin(),nums.end(),0ll); 
        if(target>sum) return -1; 
        while(target>0){
            int curr = pq.top();
            pq.pop();
            //not needed curr remove it 
            if(sum-curr>=target){
                sum-=curr;
            }
            else if(curr<=target){
                sum-=curr;
                target-=curr;
            }
            else{
                pq.push(curr/2);
                pq.push(curr/2);
                step++;
            }
        }
    return step;
    }
};
