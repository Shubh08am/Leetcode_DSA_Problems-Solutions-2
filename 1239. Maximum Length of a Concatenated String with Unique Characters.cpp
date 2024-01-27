class Solution {
public:

    bool isPossible(map<char,int>&m,string s){
        bool f = 1;
        int n = 1<<(29);
        for(int i = 0; i < s.size(); i++){
            if(m[s[i]] > 0){
                f = 0;
            }
            if( (n&(1<<(s[i]-'a'))) == 0)
            n = (n|(1<<(s[i]-'a')));
            else f = 0;
        }
        return f;
    }
    int fun(int ind,map<char,int>&m,int n,vector<string>&arr){
        if(ind == n)return 0;

        int take = 0;
        int notTake = 0;
        notTake = fun(ind+1,m,n,arr);
        for(int i = ind; i < n; i++){
            if(isPossible(m,arr[i])){
                for(int j = 0; j < arr[i].size(); j++)m[arr[i][j]]++;
                int a = arr[i].size()+fun(i+1,m,n,arr);
                take = max(take,a);
                for(int j = 0; j < arr[i].size(); j++)m[arr[i][j]]--;
            }
            
        }
        return max(take,notTake);
    }
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        map<char,int>m;
        return fun(0,m,n,arr);
    }
};
