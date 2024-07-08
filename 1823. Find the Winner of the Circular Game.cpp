class Solution {
public:
    int findTheWinner(int n, int k) {
       int res=0,i=2;
        while(i<=n){ 
            res=(res+k)%i;
            i++;
        } 
    return 1+res;
    }
};
