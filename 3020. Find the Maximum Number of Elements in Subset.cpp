class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        int len=0;
        unordered_map<int,int>freq;
        for(auto&it:nums) freq[it]++;
        sort(nums.begin(),nums.end()); 
        for(int i=0;i<n;i++){
            int curr=0,val=nums[i];
            if(nums[i]==1) continue;
            while(freq[val]>1){
                curr+=2;
                val=1ll*val*val;
            }
       //     cout<<curr<<"\n";
            if(freq[val]==1){
                curr++;
            }
            //16 16 no in between reduce cnt by 1 
            if(freq[val]==0){
                curr--;
            }
            len=max(len,curr);
        }
        if(freq[1]%2==0) len=max(len,freq[1]-1);
        if(freq[1]%2==1) len=max(len,freq[1]);
        return len;
    } 
};
