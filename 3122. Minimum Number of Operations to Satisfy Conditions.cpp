class Solution {
public:
    int minimumOperations(vector<vector<int>>& g) {
        int n=g.size(),m=g[0].size(),r=1e9,non=0; 
       vector<vector<int>>a(m+2,vector<int>(12,1e9)) ; 
          while(non<10){
            a[0][non]=0;
              non++;
        }
        
        //first col 0 
        for(int j=0;j<m;j++){
            for(int no=0;no<10;no++){
                int curr  =0; 
                int i=0,q=0; 
                while(i<n){ curr = curr + (g[i][j]!=no) ; i++;}
                 
                while(q<10){ 
                    if(no!=q){
                        //cnt step  
                        int val1 = a[j+1][no] ; 
                        int val2 = a[j][q] ; 
                        a[j+1][no] = min(val1,val2+curr);
                        
                    }
                    q++;
                }
                
                
            }
        }
         int no=0; 
        while(no<10){
            r=min(r,a[m][no]);
            no++;
        }
        if(r==1e9) return -1;
      return r ;
    }
};
