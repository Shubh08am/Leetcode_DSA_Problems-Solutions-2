class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        /*
            Brute force -> tle :( 
            now, try bfs 
            (0,0) -> (1,0) -> (0,1) -> (2,0) -> (1,1) -> (0,2) -> (2,1) -> (1,2) -> (2,2)
        */ 
        queue<pair<int,int>>q; 
        q.push({0,0});
        int n = nums.size();
        vector<int>diagonal;
        while(!q.empty()){
            int r = q.front().first ; 
            int c = q.front().second; 
            if(r<n && c<nums[r].size())diagonal.push_back(nums[r][c]);
            q.pop();
            //r+1,c -> always from first column i.e c=0 --> upper diagonal
            if(r+1<n && c==0) q.push({r+1,c}); 
            //r,c+1 
            if(r<n && c+1<nums[r].size())q.push({r,c+1});
        }
    return diagonal;
    }
};
