class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string a = "qwertyuiopQWERTYUIOP" , b = "asdfghjklASDFGHJKL" , c="zxcvbnmZXCVBNM";
        set<char>a1(a.begin(),a.end());
        set<char>a2(b.begin(),b.end());
        set<char>a3(c.begin(),c.end());
        vector<string>ans;
        for(auto&it:words){
            int cnt1=0,cnt2=0,cnt3=0;
            for(auto&x:it){
                cnt1+=a1.count(x);
            }
            for(auto&x:it){
                cnt2+=a2.count(x);
            }
            for(auto&x:it){
                cnt3+=a3.count(x);
            }
           // cout<<it<<" "<<cnt1<<" "<<cnt2<<" "<<cnt3<<"\n";
            if(cnt1==it.size() || cnt2==it.size() || cnt3==it.size()){
                ans.push_back(it);
            }
        }
    return ans;
    }
};
