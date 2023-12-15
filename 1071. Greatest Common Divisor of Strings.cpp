class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int n=str1.size(),m=str2.size(),len=min(n,m);
        string ans="";
        if(len==m){
            string curr="";
            for(int i=0;i<m;i++){
                curr+=str2[i];
                string new_curr=curr;
                string new_curr2=curr;
                while(new_curr.size()<n) new_curr+=curr; 
                while(new_curr2.size()<m) new_curr2+=curr; 
                if(new_curr==str1 && new_curr2==str2){
                    ans=max(ans,curr);
                }
            }
        }
        else{
            string curr="";
            for(int i=0;i<n;i++){
                curr+=str1[i];
                string new_curr=curr;
                string new_curr2=curr;
                while(new_curr.size()<m) new_curr+=curr; 
                while(new_curr2.size()<n) new_curr2+=curr; 
                if(new_curr==str2 && new_curr2==str1){
                    ans=max(ans,curr);
                }
            }
        }
    return ans;
    }
};
