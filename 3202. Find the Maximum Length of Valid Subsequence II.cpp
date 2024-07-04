class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        /*
        x%k+y%k = y%k+z%k
        i.e x%k=z%k -> only when x=z over mod k 
        i.e pattern of xyxyxyxy -> find largest alternating sub sequence here 
        */ 
        int n=nums.size(),len=0;
        vector<vector<int>>position(1001) ; 
        for(int i=0;i<n;i++){
            position[nums[i]%k].push_back(i);
        }
        //O(K*N) :- overall
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                auto position1 = position[i] ; 
                auto position2 = position[j] ; 
                int last=-1,curr_len=0;
                int from1=0,from2=0; 
                while(1){
                    while(from1 < position1.size() && position1[from1] <= last) from1++;
                    if(from1==position1.size()) break;
                    last=position1[from1]; 
                    curr_len++; from1++;     
                    while(from2 < position2.size() && position2[from2] <= last) from2++;
                    if(from2==position2.size()) break;
                    last=position2[from2]; 
                    curr_len++; from2++;
                }
            len=max(len,curr_len);
            }
        }
        return len;
    }
};
