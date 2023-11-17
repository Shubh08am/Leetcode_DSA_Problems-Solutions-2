#define ll long long
class Solution {
public:
    long long distributeCandies(int n, int limit) {
        ll candy=0;
        ll maxi = min(limit,n);
        for(ll i=0;i<=maxi;i++){
            /*2 people ko alloted candy ka quantity x hona chahiye aur dono ke pass <=y candy hona chahiye individually
            ab hame btana hain kitne ways mein ye krskte*/
            ll left = n-i; 
            if((left+1)/2>limit) continue;
            if(left<=limit) candy+=left+1;
            else candy+=2*limit-left+1;
        }
    return candy;
    }
};
