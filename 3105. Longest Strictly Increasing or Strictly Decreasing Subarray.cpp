class Solution {
public:
    int longestMonotonicSubarray(vector<int>& arr) {
        int max = 1, len = 1,n=arr.size();
         for (int i=1; i<n; i++){
        if (arr[i] > arr[i-1]) len++;
        else{
            if (max < len)    
                max = len;
                             len = 1;    
        }    
    }
     
    if (max < len)  max = len;
        
    reverse(arr.begin(),arr.end());
        
     len = 1;
         for (int i=1; i<n; i++){
        if (arr[i] > arr[i-1]) len++;
        else{
            if (max < len)    
                max = len;
                             len = 1;    
        }    
    }
     
    if (max < len)  max = len;
        
    return max;
    
    }
};
