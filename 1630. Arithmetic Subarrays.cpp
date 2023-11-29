class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        //brute -> for every l-r range sort nums and check that diff b/w consecutive elements are same 
        int n=nums.size(),m=l.size();
        vector<bool>ap(m);
        for(int i=0;i<m;i++){
            int li = l[i] , ri=r[i] ; 
            vector<int>cp(nums.begin()+li,nums.begin()+ri+1);
            multiset<int>s(cp.begin(),cp.end()); 
            int mini = *(s.begin()) ;
            int maxi = *(s.rbegin());
            int len = ri-li;
            int isDiv = (maxi-mini)%len;
            //cout << i<< " "<< mini << " "<<maxi << " "<< len << " "<< isDiv <<"\n";
            bool flg=1;
            if(isDiv!=0){
                //cout<<i<<"\n";
                flg=false;
                continue;
            }
            else{
                //cout<<i<<"\n";
                int d = (maxi-mini)/len;
                int a = mini+d;
               // cout<<i<<" "<<a<<" "<<d<<"\n";
                while(a<maxi){
                    if(!s.count(a)){
                        flg=false;
                        break;
                    }
                    //cout<<i<<" "<<a<<" "<<flg<<"\n";
                    a+=d;
                }
            }
            ap[i]=flg;
        }
    return ap;
    }
};
