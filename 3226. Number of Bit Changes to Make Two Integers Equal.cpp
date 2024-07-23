class Solution {
public:
    int minChanges(int n, int k) {
        int cnt=0,m=(n|k);
        if(m!=n) return -1;
        for(int i=31;i>=0;i--){
            int a=((n>>i)&1);   
            int b=((k>>i)&1);
            if(a!=b) cnt++;
        //    if(a!=b && a==0 && b==1) return -1;
        }
        return cnt;
    }
};
