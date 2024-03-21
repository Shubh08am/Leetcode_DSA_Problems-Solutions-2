class Solution {
public:
    bool isSubstringPresent(string s) {
        map<string,int>v1,v2; 
        int n = s.size(); 
        for(int i=0;i<n;i++){
            string a;
            for(int j=i;j<n;j++){
                a+=s[j]; 
              if(a.size()==2)  v1[a]++;
            }
        }
        reverse(s.begin(),s.end()) ; 
        
        for(int i=0;i<n;i++){
            string a;
            for(int j=i;j<n;j++){
                a+=s[j]; 
              if(a.size()==2)  v2[a]++;
            }
        }
        
        for(auto i : v1) {
            if(v2[i.first]>0) return 1;
        }
        return 0;
    }
};
