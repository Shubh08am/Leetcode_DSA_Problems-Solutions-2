class Solution {
public:
    string decodeMessage(string key, string message) {
        map<char,char>mp;
        int i=0;
        char c='a';
        for(auto ch : key){
            if(ch!=' '&&mp.find(ch)==mp.end()){
                mp[ch]=c;
                c++;
            }
        }
        mp[' ']=' ';
        string ans="";
        for(auto it : message){
            ans+=mp[it];
        }
    return ans;
    }
};
