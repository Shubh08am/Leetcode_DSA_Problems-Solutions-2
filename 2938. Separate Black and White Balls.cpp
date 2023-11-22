#define ll long long
class Solution {
public:
    long long minimumSteps(string s) {
        vector<long long>v,vv;
        ll n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='1') v.push_back(i) ; 
            else vv.push_back(i) ; 
        }
        ll a = v.size() , b=vv.size(); 
        ll i=0,j=b-1,ans=0;
        while(i<b){
            ans+=abs(vv[i]-i);
            i++;
        }
    return ans;
    }
};
