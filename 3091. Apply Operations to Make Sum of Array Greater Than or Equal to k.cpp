class Solution {
public:
    int minOperations(int k) {
        int a = INT_MAX;
        for(int i=0;i<k;i++){
            int curr = (k-1)/(i+1) , val = i+curr; 
            a=min(a,val);
        }
        return a;
    }
};
