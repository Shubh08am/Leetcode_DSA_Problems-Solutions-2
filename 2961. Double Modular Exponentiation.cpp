#define ll long long
class Solution {
public:
    ll binMultiply(ll a , ll b){
      ll ans=0;   
  while(b>0){
     if(b&1){
        ans=(ans+a);
    }
    a = (a+a); 
    b>>=1 ; 
  }
  return ans;
}
//leads to tle many times therefore use next one
ll binExp(ll a , ll b){
    ll ans=1;
  while(b>0){
    if(b&1){
        ans=binMultiply(ans,a) ;
    }
    a = binMultiply(a,a); 
    b>>=1 ; 
  }
  return ans;
} 
ll binExp2(ll a , ll b,ll mod){
    ll ans=1;
  while(b>0){
    //see if set-bit 
    if(b&1){
        ans=(ans*a*1LL)%mod;
    }
    a = (a*a*1LL)%mod;  //go to next power
    b>>=1 ; //right-shift the bit
  }
  return ans;
}
    vector<int> getGoodIndices(vector<vector<int>>& v, int t) {
        vector<int>ans;int i=0; 
        for(auto it : v){
            ll a=it[0],b=it[1],c=it[2],d=it[3];
            ll ab = 1ll*binExp2(a,b,10);
         //   ab%=10;
            ll bc = 1ll*binExp2(ab,c,d);
         //   bc%=d;
            if(bc==t) ans.push_back(i);
            i++;
        }
        return ans;
    }
};
