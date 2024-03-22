#define ll long long
class Solution {
public:
    long long countSubstrings(string s, char c) {
         ll b = 0 , a = 0,n=s.size();
        for (int i = 0; i < n; i++) {
 
        if (s[i] == c)
            a++;
 
        if (s[i] == c)
            b += a;
    }
     return b;
    }
};
