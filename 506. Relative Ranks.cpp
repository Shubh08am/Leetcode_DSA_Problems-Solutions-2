class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        vector<string>ranks(n); 
        vector<pair<int,int>>pos; 
        for(int i=0;i<n;i++) pos.push_back({score[i],i});
        sort(pos.rbegin(),pos.rend()); 
        
        for(int i=0;i<n;i++){
            if(i==0) ranks[pos[i].second]="Gold Medal";
            else if(i==1) ranks[pos[i].second]="Silver Medal";
            else if(i==2) ranks[pos[i].second]="Bronze Medal";
            else ranks[pos[i].second]=to_string(i+1);
        }
    return ranks;
    }
};
