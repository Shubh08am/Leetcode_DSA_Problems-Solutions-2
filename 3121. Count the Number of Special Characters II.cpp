class Solution {
public:
    int numberOfSpecialChars(string w) {
        map<char,vector<int>>mp; 
        int n=w.size() , a=0; 
        for(int i=0;i<w.size();i++){
            if(w[i]>='a' && w[i]<='z'){
                mp[w[i]].push_back(i);
            }
        }
        map<char,int>v,vv,pos; 
        for(int i=0;i<w.size();i++){
            if(w[i]>='A' && w[i]<='Z' && !vv.count(w[i])){
                vv[w[i]]=i; 
                                          char see = (char)tolower(w[i]) ;
            pos[see]=i;
            }
        }
        for(int i=0;i<w.size();i++){
                        if(w[i]>='A' && w[i]<='Z' && vv.count(w[i])){
                          char see = (char)tolower(w[i]) ;
                            if(v[see]==0 && mp[see].size()>0 &&  mp[see].back() < pos[see]) {a++; v[see]=1; }
                    }

        }
        return a;
    }
};
