class Solution {
public:
    int solve(vector<int>& colors) {
        int first = -1 , last = -1 , n = colors.size(); 
        unordered_set<int>s; 
        for(int i=0;i<n/2;i++){
          if(!s.count(colors[i]))  { 
           if(first==-1){
                s.insert(colors[i]) ; 
                first=i ;
            } 
          }
          if(!s.count(colors[n-i-1]))  { 
            if(last==-1) {
                s.insert(colors[n-i-1]) ; 
                last=max(n-i-1,last) ; 
            }
          }
        }
        if(n&1){
            if(!s.count(colors[n/2])) last=max(last,n/2);
        }
    return abs(last-first) ; 
    }
    int maxDistance(vector<int>& colors) {
       int option1 = solve(colors) ; 
       reverse(colors.begin(),colors.end()); 
       int option2 = solve(colors) ; 
    return max(option1,option2) ; 
    }
};
