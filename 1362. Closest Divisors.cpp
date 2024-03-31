class Solution {
public:
    vector<int>findDivisors(int num){
        int a=0,b=1e9,diff=INT_MAX; 
        for(int i=1;i<=sqrt(num);i++){
            if(num%i==0){
                if(abs(num/i-i) < diff){
                    b=num/i;a=i;
                    diff=abs(b-a);
                }
            }
        } 
    return {a,b};
    }
    vector<int> closestDivisors(int num) {
        //find divisors of both num+1 and num+2 and than check 
        vector<int>num1 = findDivisors(num+1) ;  
        vector<int>num2 = findDivisors(num+2) ;       
        return abs(num1[0]-num1[1])>abs(num2[0]-num2[1])?num2:num1;
    }
};
