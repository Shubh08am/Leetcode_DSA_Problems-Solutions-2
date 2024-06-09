class Solution {
public:
    string solve(string &s){
       stack<char>ms; 
        for(auto&ch:s){
            if(!ms.empty() && isdigit(ch)){
                if(ms.top()>='a' && ms.top()<='z') ms.pop();
            }
            else if(ch>='a' && ch<='z') ms.push(ch);
        }
        string res=""; 
        while(!ms.empty()){
            res+=ms.top();
            ms.pop();
        }
        reverse(res.begin(),res.end());
        return res; 
    }
    string clearDigits(string s) {
        return solve(s) ;
    }
};
