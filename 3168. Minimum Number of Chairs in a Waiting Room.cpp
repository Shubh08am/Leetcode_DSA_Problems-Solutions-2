class Solution {
public:
    int minimumChairs(string s) {
        int a=0,b=0; 
        for(auto&ch:s){
            if(ch=='E'){
                a++;
                b=max(a,b);
            }
            else a--;
        }
        return b;
    }
};
