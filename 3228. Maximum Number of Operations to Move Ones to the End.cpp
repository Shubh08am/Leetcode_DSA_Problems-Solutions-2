class Solution {
public:
    int maxOperations(string s) {
        int n = s.length(),res=0,a=0;
        for(int i = 0; i <= n-2; i++){
            if(s[i] == '1') a++;
            if(s[i] == '1' && s[i+1] == '0') res += a;
        }
        return res;
    }
};
