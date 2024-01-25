class Solution {
public:
    int findAll(vector<pair<int,char>>&pos,unordered_map<char,int>&freq,int i,int curr){
        int cnt=0,k=8,j=i;
        while(j<pos.size() && k>0){
            cnt+=freq[pos[j].second]*curr;
            k--;j++;
        }
    return cnt;
    }
    int minimumPushes(string word) {
        //first we should try to map every key for the first time from 2-9 
        //than again keep following this process 
        vector<pair<int,char>>pos;
        unordered_map<char,int>freq;
        for(auto&ch:word){
            freq[ch]++;
        }
        for(auto&it:freq){
            pos.push_back({it.second,it.first});
        }
        sort(pos.rbegin(),pos.rend());
        int ans=0,curr=1;
        for(int i=0;i<pos.size();i++){
            ans+=(findAll(pos,freq,i,curr));
            i+=7;
            curr++;
        }
    return ans;
    }
};
