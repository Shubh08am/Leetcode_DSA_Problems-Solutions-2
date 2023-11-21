class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int n = s1.size() , m=s2.size() , y=s3.size(); 
        int x = min({n,m,y}) ; 
        int j=0;
        while(j<x && s1[j]==s2[j] && s2[j]==s3[j]){
            j++;
        }
        int ans = n+m+y;
        ans-=3*j;
        return !j?-1:ans;
    }
};
