#define ll long long 
const int mod = 1e9+7;
class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
       //make a and b as close to each other 
			ll A = 0 , B = 0;
			for(int x=49;x>=n;x--){
					bool setA = (a&(1LL<<x));
					bool setB = (b&(1LL<<x));	 
					if(setA){
						A=(A^(1LL<<x));
					}
					if(setB){
						B=(B^(1LL<<x));
					}
			}
			for(int x=n-1;x>=0;x--){
							bool setA = (a&(1LL<<x));
							bool setB = (b&(1LL<<x));
							
							if(setA == setB){
								A=(A^(1LL<<x));
								B=(B^(1LL<<x));
							}
							//Now decrease larger one and increase smaller one 
							else if(A>B){
									B=(B^(1LL<<x));	//smaller decrease
							}
							else if(A<=B){
									A=(A^(1LL<<x)); //smaller decrease
							}
			} 
      A%=mod;B%=mod;
		return (1LL*(A)*(B))%mod; 
    }
};
