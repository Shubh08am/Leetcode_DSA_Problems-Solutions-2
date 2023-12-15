class Solution {
public:
    vector<int> findPeaks(vector<int>& b) {
        vector<int>a ; 
        for(int i=1;i<b.size()-1;i++){
            if(b[i]>b[i-1] && b[i]>b[i+1]) a.push_back(i);
        }
        return a;
    }
};
