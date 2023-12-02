#define ll long long
class Solution {
public:
     ll maxArea(ll h, ll w, vector<int>& hC, vector<int>& vC) {   
        sort(hC.begin(), hC.end());
        sort(vC.begin(), vC.end());
         ll curr=0,op=0,area=0;
        for(int i=1; i<vC.size(); i++){
            ll diff = vC[i] - vC[i-1];
            if(diff-1==0){
                ++curr;
            }
            else if(diff-1!=0){
                ++curr;
                op=max(op,curr);
                curr=0;
            }
       //      cout<< curr << " "<<op <<"\n";
        }
         //last one left 
        ++curr;
        op=max(op,curr);
         ++op;
   //       cout<< curr << " "<<op <<"-1\n";
        ll area1=1ll*op*op;
        
        curr=0,op=0;
        for(int i=1; i<hC.size(); i++){
            ll diff = hC[i] - hC[i-1];
            if(diff-1==0){
                ++curr;
            }
            else if(diff-1!=0){
                ++curr;
                op=max(op,curr);
                curr=0;
            }
      //      cout<< curr << " "<<op <<"\n";
        }
         //last one left 
        ++curr;
        op=max(op,curr);
         op++;
        ll area2=1ll*op*op;
     //   cout<< curr << " "<<op <<"-2\n";
     //   cout<< area1 << " "<<area2 <<"-3\n";

         area = area1<=area2?area1:area2;
         return area;
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hC, vector<int>& vC) {
        return maxArea(n,m,hC,vC);
    }
};
