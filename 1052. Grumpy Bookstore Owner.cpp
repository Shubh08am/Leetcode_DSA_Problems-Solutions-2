class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        /*
     prefix[i] = prefix[i-1]+customers[i] ; 
     prefix  =    1 1 2 4 5 6 13 18 
        
     modify prefix[i] = prefix[i]-prefix[i-minutes] , i start from minutes 
     prefix = 1 1 2 3 4 4 9 13 
        
      now,find max prefix and its index , if multiple take first max 
      and neglect max_ind-k position and than again see for left position with 0 grumpy
        */
        int n = customers.size(),ans=0; 
        vector<int>prefix(n,0); 
        for(int i=0;i<n;i++){
           if(grumpy[i]==0) {ans+=customers[i] ; customers[i]=0;}
        }
        prefix[0]=customers[0];
        for(int i=1;i<n;i++) prefix[i]=(prefix[i-1]+customers[i]);
        //for(auto i : prefix) cout<<i<<" ";
        //cout<<"\n";
        vector<int>new_prefix=prefix;
        for(int i=minutes;i<n;i++)  new_prefix[i]=prefix[i]-prefix[i-minutes];
       //for(auto i : new_prefix) cout<<i<<" ";
      //  cout<<"\n";
        int max_customer=0; 
        for(int i=0;i<n;i++){
            if(new_prefix[i]>max_customer){
                max_customer=new_prefix[i];
            }
        }
       // cout<<max_customer<<"\n";
        return max_customer+ans;
    }
};
