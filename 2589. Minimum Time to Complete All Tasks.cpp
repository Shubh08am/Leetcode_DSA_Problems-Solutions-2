class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        //sort on the basis of end time and do task as late as possible
        sort(tasks.begin(),tasks.end(),[&](auto&a,auto&b){
            return a[1]==b[1]?a[0]<b[0]:a[1]<b[1];
        });
        int time=0;
        unordered_map<int,bool>vis;
        for(auto&it:tasks){
            int start=it[0],end=it[1],duration=it[2];
            for(int i=start;i<=end;i++){
                if(vis[i]) duration--;
            }
            //now do tasks as late as possible 
            for(int j=end;j>=start && duration>0 ; j--){
                if(vis[j]) continue;
                vis[j]=1;
                duration--;
            }
        }
        for(auto&it:vis) time+=it.second;
    return time;
    }
};
