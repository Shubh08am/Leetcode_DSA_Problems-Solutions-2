class Solution {
public:
    int maxCoins(vector<int>& piles) {
     /*
9 8 7 6 5 4 3 2 1
9 8 1 -> 8
7 6 2 -> 6 
5 4 3 -> 4 


8 7 4 2 2 1 
8 7 1 -> 7 
4 2  2 -> 2 
*/
sort(piles.rbegin(),piles.rend());
int n = piles.size() , i=1,ans=0;
while(i<2*n/3){
    ans+=piles[i];
	i+=2;
}
return ans;   
    }
};
