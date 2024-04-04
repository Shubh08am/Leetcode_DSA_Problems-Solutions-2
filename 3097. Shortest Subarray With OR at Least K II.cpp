class Solution {
public: 
    int smallestOr(vector<int>&w,int k){
        int i=0,j=0,n=w.size(),len=1e9,orr=0; 
        //sliding window 
        vector<int>setBit(35,0) ; 
        while(j<n){
            long val = w[j];
            orr|=val;
            int pos=0;
            while(val>0 && pos<31){
                setBit[pos++]+=(val&1);
                val>>=1ll;
            } 
            
            //shrink window 
            while(orr>=k && j>=i){
                len=min(len,j-i+1);

            int pos=0,val=w[i];
            while(val>0 && pos<31){
                setBit[pos++]-=(val&1);
                val>>=1ll;
            }
                
                //find the new orr 
                int new_orr = 0 ; 
                long l=0,num=1; 
                while(l<31){
                    if(setBit[l]!=0){
                        new_orr+=num;
                    }
                    num=(num*2*1ll);
                    l++;
                } 
               // cout << orr << " "<< new_orr << "\n"
                orr = new_orr; 
                i++;
            }
            j++;
        }
    return len==1e9?-1:len;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int a=0; 
        for(auto i : nums) a|=i; 
        if(a<k) return -1; 
        return smallestOr(nums,k);
    }
};
