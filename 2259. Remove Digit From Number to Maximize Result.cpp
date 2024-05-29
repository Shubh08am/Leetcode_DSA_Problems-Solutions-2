class Solution {
public:
    string removeDigit(string number, char digit) {
        //12131 -> 1213 , 2131 , 1231 
        //4525621343243244 -> 525621343243244 , 452562133243244 , 452562134323244 , 452562134324324
        int first = -1 , last = -1 , n=number.size(); 
        for(int i=0;i<n;i++){
            if(i+1<n && number[i]==digit && number[i+1]>digit){
                return number.substr(0,i)+number.substr(i+1) ;
            }
            if(number[i]==digit) last=i;
        }
        string two = number ; 
        two.erase(two.begin()+last) ; 
        return two;
    }
};
 
