class Solution {
public:
    int countPalindromicSubsequence2(string s) {
        int count=0;
        // left[i]= first occurrence of char('a'+i)
        // right[i]= last occurrence of char('a'+i)
        vector<int>left(26,-1),right(26,-1);
        
        // 'v' is 2d matrix where v[i][j] = count of char('a'+i) till the index j where 0<=j<s.length()
        vector<vector<int>>v(26,vector<int>(s.length()));
        for(int i=0;i<26;i++) {
            for(int j=0;j<s.length();j++) {
                if(s[j]==char('a'+i)) {
                    v[i][j]=(j>0?v[i][j-1]+1:1);
                }
                else {
                    v[i][j]=(j>0?v[i][j-1]:0);
                }
            }
        }

        /*for(auto it : v){
            for(auto c : it) cout<<c<<" ";
            cout<<"\n";
        }*/
        for(int i=0;i<s.length();i++) {
            if(left[s[i]-'a']==-1) {
                left[s[i]-'a']=i;
            }
            right[s[i]-'a']=i;
        }
        
        // check for all 26 alphabets 
        for(int i=0;i<26;i++) {
            // if the gap between first and last occurrence of a character is 2 or more that means some characters are there in between
            if(right[i]-left[i]>=2) {
                // so count no. of unique characters in (left[i],right[i]) interval
                for(int j=0;j<26;j++) {
                    if(v[j][right[i]-1]-v[j][left[i]]>0) {
                  //  cout<< right[i] << " "<< left[i] << "\n";
                  //      cout << v[j][right[i]-1] << " "<< v[j][left[i]] << "\n";
                        count++;
                    }
                }
            }
        }
        return count;
    }
    int countPalindromicSubsequence(string s) {
        int unique=0,n=s.size();
        vector<int>vis(26,0);
        map<char,set<int>>pos;
        for(int i=0;i<n;i++){
            pos[s[i]].insert(i);
        }
        for(int i=0;i<n;i++){
            if(vis[s[i]-'a'] || pos[s[i]].size()<2) continue;
            int start = *(pos[s[i]].begin()) , end = *(pos[s[i]].rbegin()) ;
            if(end-start<2) continue;
            //unique charcter between start+1 and end-1 
            set<char>st(s.begin()+start+1,s.begin()+end);
            //cout<<s[i] << " "<< start << " "<< end << "\n";
            unique+=st.size();
            vis[s[i]-'a']=1;
        }
    //return unique;
    return countPalindromicSubsequence2(s);
    }
};
