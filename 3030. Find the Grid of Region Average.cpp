class Solution {
public:
    void solve(vector<vector<int>>& image, int threshold,int m,int n,int i,int j,map<int,map<int,vector<int>>>&mp){
        int a  = 0 , b = 0 , curr_sum=0; 
        for(int p=i;p<i+3;p++){
            for(int k=j;k<j+3;k++){
                
               // a=max(a,image[p][k]);
                if(p<i+2){
                    int val=abs(image[p][k]-image[p+1][k]);
                    a=max(a,val);
                }
                if(k<j+2){
                    int val=abs(image[p][k]-image[p][k+1]);
                    a=max(a,val);
                }
               // cout << a << " ";
                curr_sum+=image[p][k];
            }
        }
        
        //within threshold 
        int diff = a; 
      //  cout << a << " ";
        if(diff<=threshold){
              for(int p=i;p<i+3;p++){
                for(int k=j;k<j+3;k++){
                    int val = curr_sum/9 ; 
                    mp[p][k].push_back(val);
                 }
              }
        }
    }
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
        int m=image.size(),n=image[0].size();
        vector<vector<int>>result=image; 
        map<int,map<int,vector<int>>>mp;

        //take average of 3*3 cell 
        for(int i=0;i<m-2;i++){
            for(int j=0;j<n-2;j++){
               solve(image,threshold,m,n,i,j,mp); 
            }
        }
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int sz=mp[i][j].size();
                if(sz==0) continue; 
                long long curr_sum = accumulate(mp[i][j].begin(),mp[i][j].end(),0ll);
                result[i][j] = curr_sum/sz;
            }
        }
       return result;
    }
};
