class Solution {
public:
    //KMP   
    vector<int> getLps(string pat){
    int m = pat.size();
    vector<int>lps(m);
    int prev = 0;
    int ind = 1;
    while (ind < m){
         if (pat[ind]==pat[prev]){
            prev++;
            lps[ind]=prev;
            ind++;
        }
        else if (prev==0){
            lps[ind]=0;
            ind++;
        }
        else{
            prev = lps[prev-1];
        }
    }
    return lps;
}
    // occurence
long long solve(string str, string pat,long long ans){
    vector<int> lps = getLps(pat);
    int n = str.size();
    int m = pat.size();
    int patIdx = 0;
    int strIdx = 0;
    while (strIdx < n){
         if (str[strIdx] == pat[patIdx]){
            patIdx++;
            strIdx++;
        }
        if (patIdx == m){
           ans++;
             patIdx = lps[patIdx-1];
        }
        else if (strIdx < n){
            if (str[strIdx]!=pat[patIdx]){
                if (patIdx != 0)
                     patIdx = lps[patIdx-1];
                else
                     strIdx++;
            }
        }
    }
    return ans;
}
    int countMatchingSubarrays(vector<int>& nums, vector<int>& p) {
        string s1 , s2 ; 
        int n = nums.size(),m=p.size() ; 
        for(int i=0;i<n-1;i++){
            if(nums[i+1]>nums[i]) s1+='1';
            else if(nums[i+1]<nums[i]) s1+='2';
            else s1+='0';
        }
         for(int i=0;i<m;i++){
            if(p[i]==1) s2+='1';
            else if(p[i]==0) s2+='0';
            else s2+='2';
        }
        
        long long ans = solve(s1,s2,0);
        return ans;
    }
};
