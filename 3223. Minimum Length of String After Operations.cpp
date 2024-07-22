class Solution {
public:
    int minimumLength(string s) {
        int len=0;
        map<char,int>freq; 
        for(auto&it:s) freq[it]++; 
        for(auto&[x,y]:freq){
            if(y%2==0) len+=2; 
            else if(y%2==1) len++;
        }
        return len;
    }
};
