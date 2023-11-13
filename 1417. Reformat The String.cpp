class Solution {
public:
    string reformat(string s) {
        int n=s.size(),cnt=0,i=0;
        string s1="",s2="";
        for(auto ch : s){
            cnt+=ch>='0'&&ch<='9';
        }
        for(auto ch : s){
            if(ch>='0'&&ch<='9')s2+=ch;
            else s1+=ch;
        }
        if(abs((int)s1.size()-(int)s2.size())>1) return "";
        string ans="";
        
        if(s1.size()>=s2.size()){
            while(i<n/2){
            ans+=s1[i];
            ans+=s2[i];
            i++;
            }
        if(i<s1.size()) ans+=s1[i];
        }
        else{
            while(i<n/2){
            ans+=s2[i];
            ans+=s1[i];
            i++;
            }
        if(i<s2.size()) ans+=s2[i];
        }
    return ans;
    }
};
