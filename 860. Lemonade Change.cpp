class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cnt5=0,cnt10=0,cnt20=0; 
        for(auto&val:bills){
            if(val==5) cnt5++; 
            if(val==10){
                if(cnt5==0) return 0; 
                else {
                    cnt5--;
                    cnt10++;
                }
            }
            if(val==20){
                if(cnt5==0 && cnt10==0) return 0; 
                else{
                    if(cnt10>0 && cnt5>0){
                        cnt10--; 
                        cnt5--;
                    }
                    else if(cnt10==0 && cnt5>=3){
                        cnt5-=3;
                    }
                    else return 0;
                }
            }
        }
    return 1;
    }
};
