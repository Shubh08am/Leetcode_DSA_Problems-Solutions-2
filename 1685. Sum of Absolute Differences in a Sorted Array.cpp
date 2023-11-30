class Solution {
public:
    vector<int> getSumAbsoluteDifferences2(vector<int>& nums) {
        //preffix+suffix
        int n=nums.size();
        vector<int>preffix(n,0),suffix(n,0),ans(n);
        preffix=nums;
        suffix=nums;
        for(int i=0;i<n;i++){
            if(i>0) preffix[i]+=preffix[i-1];
            if(n-i-2>0)suffix[n-i-2]+=suffix[n-i-1];
        }
        for(auto i : preffix) cout<<i<<" ";
        cout<<"\n";
        for(auto i : suffix) cout<<i<<" ";
        cout<<"\n";
        for(int i=0;i<n;i++){
            ans[i]= (i<n-1?suffix[i+1]-nums[i]*(n-i-1):0)+(i>0?abs(preffix[i-1]-nums[i]*i):0);
        }
    return ans;
    }
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        //preffix+suffix
        int n=nums.size();
        vector<int>ans(n);
        int preffix=0,suffix=accumulate(nums.begin(),nums.end(),0);
        for(int i=0;i<n;i++){
            suffix-=nums[i];
            ans[i]= suffix-nums[i]*(n-i-1)+abs(preffix-nums[i]*i);
            preffix+=nums[i];
        }
    return ans;
    }
};
