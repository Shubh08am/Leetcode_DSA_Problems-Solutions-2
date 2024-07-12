class Solution {
public:
    int ab(string &s, int &x, int &y){
        stack<char>st; 
        int first=0; 
        for(auto&ch:s){
                if(!st.empty() && st.top()=='a' && ch=='b') {
                    first++; 
                    st.pop();
                }
                else st.push(ch); 
        }
        s="";
        while(!st.empty()){
            s+=st.top(); 
            st.pop();
        }
        reverse(s.begin(),s.end());
        return first*x; 
    }
    int ba(string &s, int &x, int &y){
        stack<char>st; 
        int first=0; 
        for(auto&ch:s){
                if(!st.empty() && st.top()=='b' && ch=='a') {
                    first++; 
                    st.pop();
                }
                else st.push(ch); 
        }
        s="";
        while(!st.empty()){
            s+=st.top(); 
            st.pop();
        }
        reverse(s.begin(),s.end());
        return first*y; 
    }
    int maximumGain(string s, int x, int y) {
        //ab,ba 
        //ba,ab 
        int way1=0,way2=0; 
        string p=s;
        way1=ab(s,x,y)+ba(s,x,y); 
        way2=ba(p,x,y)+ab(p,x,y); 
        return max(way1,way2);
    }
};
