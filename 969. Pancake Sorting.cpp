class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int>ans; 
        //bring max number of the array in the first position first 
        //and than reverse it to its original position with k = arr[i] 
        set<int,greater<int>>all(arr.begin(),arr.end()) ;
        int n=arr.size(),curr_max=*(all.begin()),i=0; 
        while(1){
            if(is_sorted(arr.begin(),arr.end())) break; 
            map<int,int>pos; 
            for(int i=0;i<n;i++) pos[arr[i]]=i; 
            int k = pos[curr_max]+1; 
            reverse(arr.begin(),arr.begin()+k); 
            reverse(arr.begin(),arr.begin()+curr_max);
            ans.push_back(k);
            ans.push_back(curr_max);
            all.erase(all.begin()); 
            curr_max=*(all.begin());
        }
    return ans;
    }
};
