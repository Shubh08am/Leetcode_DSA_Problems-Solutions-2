class Solution {
public:
    int countKeyChanges(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower); 
    //    cout<<s<<"\n";
        int cnt=0,n=s.size();
        for(int i=0;i<n-1;i++){
            if(s[i]!=s[i+1]) cnt++;
        }
        return cnt; 
    }
};
