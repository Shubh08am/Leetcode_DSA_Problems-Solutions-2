class Solution {
public:
    vector<int> findWordsContaining(vector<string>& w, char x) {
       vector<int>a;int i=0; 
        for(auto & it : w){
            int f=0; 
            for(auto y : it) f+=(x==y);
            if(f>0) a.push_back(i);
            i++;
        }
        return a;
    }
};
