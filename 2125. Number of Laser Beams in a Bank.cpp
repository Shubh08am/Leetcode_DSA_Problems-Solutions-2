class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size(),ans=0,prev=0; 
        for(int i=0;i<n;i++){
            int cnt_1 = count(bank[i].begin(),bank[i].end(),'1');
            if(cnt_1!=0){
                ans+=(prev*cnt_1);
                prev=cnt_1;
            }
        }
    return ans;
    }
};
