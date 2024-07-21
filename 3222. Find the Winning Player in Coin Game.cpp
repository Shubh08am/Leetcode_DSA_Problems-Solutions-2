class Solution {
public:
    string losingPlayer(int x, int y) {
        int turn=0;
        while(1){
            if(x>=1 && y>3){
                x--;y-=4; 
                turn++;
            }
            else break;
        }
        return turn%2==0?"Bob":"Alice";
    }
};
