class Solution {
public:
    double findMin(vector<int>& nums){
        int n=nums.size(); 
        double small=1e8; 
        priority_queue<int>maxH(nums.begin(),nums.end()); 
        priority_queue<int,vector<int>,greater<int>>minH(nums.begin(),nums.end()); 
        for(int i=0;i<=n/2;i++){
            int val1=maxH.top(); 
            int val2=minH.top(); 
            small=min(small,(val1+val2)/2.0);
            maxH.pop(); 
            minH.pop(); 
        }
        return small; 
    }
    double minimumAverage(vector<int>& nums) {
        return findMin(nums);
    }
};
