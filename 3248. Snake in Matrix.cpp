class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int xi=0,xj=0;
        for(int i=0;i<commands.size();i++){
            if(commands[i]=="DOWN"){
                xi++;
            }
            else if(commands[i]=="RIGHT"){
                xj++;
            }
            else if(commands[i]=="UP"){
                xi--;
            }
            else if(commands[i]=="LEFT"){
                xj--;
            }
        }
        return xi*n+xj;
    }
};
