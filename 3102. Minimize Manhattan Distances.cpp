class Solution {
public:
   int value(vector<int>&v,vector<vector<int>>& A,int a){
       int n = A.size(),c=0;
           if(v[0]==a){
               c=v[v.size()-1]-v[1];
           }
           else if(v[v.size()-1]==a){
               c=v[v.size()-2]-v[0];
           }
           else{
               c=v[v.size()-1]-v[0];
        }
     return c;
   }
  int value2(vector<int>&v,vector<vector<int>>& A,int b){
       int n = A.size(),c=0;
           if(v[0]==b){
               c=v[v.size()-1]-v[1];
           }
           else if(v[v.size()-1]==b){
               c=v[v.size()-2]-v[0];
           }
           else{
               c=v[v.size()-1]-v[0];
           }
     return c;
   }
   int solve(vector<vector<int>>& A){
     int n = A.size();
    vector<int> v(n), vv(n);
    for (int i = 0; i < n; i++) {
        v[i] = A[i][0] + A[i][1];
        vv[i] = A[i][0] - A[i][1];
    }
    sort(v.begin(), v.end());
    sort(vv.begin(), vv.end());
    
     int w = 1e9; 
       for(int i=0;i<n;i++){
           int a = A[i][0] + A[i][1] ; 
           int b = A[i][0] - A[i][1] ; 
           int c,d;
           
           c = value(v,A,a) ; 
         //  cout << c << " ";
          d = value2(vv,A,b) ;
        //  cout << d << " ";
           int diff = max(c,d) ; 
           w=min(w,diff);
       }
    return w;
 }
    
    int minimumDistance(vector<vector<int>>& points) {
        int n=points.size();
        return solve(points);
    }
};
