class Solution {
public:
    int minAnagramLength(string s) {
        int n = s.size(); 
        //store all the factors 
        vector<int>factors; 
        //sqrt n 
        for(int i=1;i*i<=n;i++){
            if(n%i==0) {
                factors.push_back(n/i);
                if(n/i!=i){
                    factors.push_back(i);
                }
            }
        }
        
        sort(factors.begin(),factors.end()) ; 
        // n*(n)^1/3 
        //log sorting 
         for (auto&it:factors) {
                set<string>st; //to keep a track of used word 
                int i=0; //
                while(i<=n-it){
                    string curr=s.substr(i,it);
                    sort(curr.begin(), curr.end());
                    st.insert(curr);
                    i+=it;
                }
                if (st.size()==1) return it;
            }
        return n; 
    }
};
