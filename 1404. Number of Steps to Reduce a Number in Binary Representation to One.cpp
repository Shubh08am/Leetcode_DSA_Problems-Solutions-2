class Solution {
public:
    int numSteps(string s) {
        //we cant convert s to decimal and do bfs or recursion -> runtime 
        //simulate the process with bits when odd and even 
        int operation=0; 
        while(s!="1"){
            //even case 
            while(s.back()=='0') {s.pop_back();operation++;}
            //odd case 
            if(s!="1" && s.back()=='1'){
                int n=s.size(),i=n-1; 
                while(i>=0 && s[i]=='1'){
                    s[i--]='0';
                }
                if(i>0) s[i]='1';
                else s='1'+s; 
                operation++;
            }
        }
    return operation;
    }
};
