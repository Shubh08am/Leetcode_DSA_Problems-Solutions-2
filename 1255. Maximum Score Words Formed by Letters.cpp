class Solution {
public:
    int solve(int ind,int n,vector<string>& words, vector<char>& letters, vector<int>& score,unordered_map<string,int>&freq,
              unordered_map<char,int>&track){
        if(ind>=n){
            return 0;
        } 
        string curr ; 
        int total_score = 0 ; 
        
        int notTake = solve(ind+1,n,words,letters,score,freq,track); //notTake 
        int take = 0 ;
        
        //take 
        for(int i=0;i<words[ind].size();i++){
           if(track[words[ind][i]]>0) {curr+=words[ind][i] ; track[words[ind][i]]--; } 
           else {
            //backtrack if not possible for the current word chosen 
            curr="";
            for(int j=0;j<i;j++) track[words[ind][j]]++; 
            break;
           }
        }
            if(freq[curr]>0){
                for(auto & ch:curr) total_score+=score[ch-'a'];
                freq[curr]--;
              take =  total_score + solve(ind+1,n,words,letters,score,freq,track);
                //backtrack 
                freq[curr]++;
                for(auto&ch:words[ind]) track[ch]++;
            }
        
       // cout << take << " " << notTake << "\n";
        return max(take,notTake); 
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        //recursion & backtracking 
        unordered_map<string,int>freq; 
        for(auto&w:words) freq[w]++; 
        unordered_map<char,int>track; 
        for(auto&w:letters) track[w]++; 
       return solve(0,words.size(),words,letters,score,freq,track); 
    }
};
