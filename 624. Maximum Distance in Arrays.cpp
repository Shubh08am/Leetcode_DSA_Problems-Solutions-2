class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        //all +ve -> find max and min 
        //all -ve -> find 2 abs max value i.e 2 minimum 
        //+ve & -ve -> max of (+ve max & abs of -ve max , find 2 abs max value i.e 2 minimum)
        int m=arrays.size();
        int mx=arrays[0].back(),mn=arrays[0][0],option1=0,option2=0; 
        for(int i=1;i<m;i++){
            option1=max(option1,abs(mn-arrays[i].back()));
            option2=max(option2,abs(arrays[i].front()-mx));
            mn=min(mn,arrays[i].front());
            mx=max(mx,arrays[i].back());
        }
        return max(option1,option2);
    }
};
