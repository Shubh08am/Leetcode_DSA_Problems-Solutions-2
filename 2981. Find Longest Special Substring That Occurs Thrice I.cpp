class Solution {
public:
    int maximumLength(string s) {
        map<char,vector<int>>pos; 
        int n=s.size(),max_len=-1,max_len2=0;
        for(int i=0;i<n;i++) pos[s[i]].push_back(i) ; 
        for(auto&it:pos){
            auto v = it.second; 
            sort(v.begin(),v.end()) ; 
            bool flg=0;
            //at least 3 len and difference between them is 1 
            int len = v.size(); 
            if(len<3) continue ; 
            int curr_len = -1 , prev=v[0]; 
            for(int i=1;i<len;i++){
                if(v[i]-v[i-1]!=1) {
                    flg=1 ; 
                    prev=v[i];
              // cout << v[i] << " "<< prev << " "<<v[i]-prev-1<<"\n";
                }
                else {
               //   cout << v[i] << " "<< prev << " "<<v[i]-prev-1<<"\n"; 
                    curr_len=max(curr_len,v[i]-prev-1);
                }
            }
            if(flg) max_len=max(max_len,1) ;
            if(!flg) curr_len = max(curr_len,v.back()-v.front() - 1) ; 
            max_len=max(max_len,curr_len);
            
            vector<int>sec; 
            int k=1,cl=0,p=v[0];
            map<int,int>pm;
            while(k<len){
                if(v[k]-v[k-1]!=1){
                //    cout << k << " " << cl << "  "    << p << " "<< cl-p+1 << "\n";
                    sec.push_back(cl-p+1); 
                    pm[cl-p+1]++;
                    p=v[k];
                }
                else{
                    cl=v[k];
                }
                k++;
            }
            sec.push_back(v.back()-p+1); 
            pm[sec.back()]++;
            sort(sec.rbegin(),sec.rend()) ;
      //     for(auto c : sec) cout << c << " "; 
     //      cout<<"\n";
            if(sec.size()>1 && sec[0]-sec[1]==1) max_len=max(max_len,sec[1]);
              if(sec.size()>1 && sec[0]-sec[1]==0) {
                  for(auto i : pm){
                      if(i.second>2) max_len=max(max_len,i.first);
                  else max_len=max(max_len,sec[1]-1);
                  }
              }
        }
    return max_len;
    }
};
