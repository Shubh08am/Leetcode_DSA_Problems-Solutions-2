class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& at) {
        vector<string>a;
        map<string,vector<int>>ms;
        for(auto it : at){
            int v = stoi(it[1]) ; 
             int hours = v / 100;
             int minutes = v % 100; 
            int tm = hours * 60 + minutes;
            ms[it[0]].push_back(tm);
        }
        for(auto&it:ms){
            string c = it.first; 
            vector<int>b=it.second;
            sort(b.begin(),b.end());
            int m = b.size() ; 
            if(m<3) continue;
            for(int i=0;i<m-2;i++){
                 int st = b[i] , en=b[i+2] ;
                if(en-st<60){
                    a.push_back(c);
                    break;
                }
            }
        }
        return a;
    }
};
