#define ll long long
class Solution {
public:
    ll binExp2(ll a , ll b){
    ll ans=1;
  while(b>0){
    //see if set-bit 
    if(b&1){
        ans=(ans*a*1LL);
    }
    a = (a*a*1LL);  //go to next power
    b>>=1 ; //right-shift the bit
  }
  return ans;
}
    void shortest_distance(vector<vector<int>>&matrix,int n){
         for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	          //  if(matrix[i][j]==-1)  matrix[i][j] = 1e9 ; 
	        if(i==j) matrix[i][j]=0;
	        }
	    }
	    //Floyd Warshall Algorithm 
	    for(int via=0;via<n;via++){
	        for(int i=0;i<n;i++){
	           for(int j=0;j<n;j++){
                     if(matrix[i][via]==1e9 || matrix[via][j]==1e9) continue;
	                //else update distance 
	                matrix[i][j] = min(matrix[i][j] , matrix[i][via]+matrix[via][j]) ;
	           }
	        }
	    }
	}
    int numberOfSets(int n, int d, vector<vector<int>>& r) {
        ll a=0;
        //floyd 
        ll range = binExp2(2,n) ; 
        for(ll i=0;i<range;i++){
            map<int,int>dist; 
            multiset<int>dd;
            vector<vector<int>>matrix(n,vector<int>(n,1e9));
            for(int k=0;k<n;k++){
                    if((i&(1<<k))) {dist[k]++; dd.insert(k);}
            }
            //see for matrix now 
            for(auto &it:r){
                if(!dist[it[0]] || !dist[it[1]]) continue;
                //0->1
                matrix[it[0]][it[1]]=min(it[2],matrix[it[0]][it[1]]);
                //1->0
                matrix[it[1]][it[0]]=min(it[2],matrix[it[0]][it[1]]);
            }
            shortest_distance(matrix,n);
            //see dist now 
            int curr=0;
            for(auto &a : dd){
                for(auto &b: dd){
                    if(matrix[a][b]>d){
                        curr=1;
                        break;
                    }
                }
             //   cout<<i<<" "<<range<<"\n";
                    //dist not fine no more check 
                    if(curr==1) break;
            }
            //cout<<curr<<"\n";
            a+=(curr==0);
        }
    return a;
        
    }
};
