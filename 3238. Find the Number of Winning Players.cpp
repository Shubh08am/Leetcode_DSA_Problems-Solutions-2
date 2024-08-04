class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        int cnt = 0;
        vector<vector<int>>freq(n,vector<int>(11,0));
        vector<int>player(n,-1);
        for(auto i:pick){
            freq[i[0]][i[1]]++;
            if(freq[i[0]][i[1]]>i[0] && player[i[0]]==-1){
                cnt++;
                player[i[0]]=1;
            }
        }
        return cnt;
    }
};
