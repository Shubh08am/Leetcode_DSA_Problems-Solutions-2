class Solution {
public:
    int an(map<int,int>&m,map<int,int>&mp){
        unordered_set<int>s;
        for(auto&i:m) {if(i.second>0) s.insert(i.first);}
        for(auto&i:mp) {if(i.second>0) s.insert(i.first);}
        return s.size();
    }
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(); 
        int a=0; 
        map<int,int>m,mp,p;
        for(auto i : nums1) m[i]++;
         for(auto i : nums2) mp[i]++;
        vector<int>common; 
        
        int r1=0,r2=0; 
        
        for(auto i : nums1){
            if(m[i]>1) {
                if(r1==n/2) break;
                r1++;
                m[i]--;
                if(m[i]==0) m.erase(i); 
            }
        }
        
        for(auto i : nums2){
            if(mp[i]>1) {
                 if(r2==n/2) break;
                r2++;
                mp[i]--;
                  if(mp[i]==0) mp.erase(i); 
            }
        }
    //    cout << r1 << " "<<r2 << "\n";
        if(r1==n/2 and r2==n/2) {long ans = an(m,mp); return ans; }
        
        
        for(auto&it:nums1){
            if(mp[it]>0 && p[it]==0) {common.push_back(it);p[it]=1;}
        }
        for(auto&it:nums2){
            if(m[it]>0 && p[it]==0) {common.push_back(it);p[it]=1;}
        }
        
   //     for(auto i : common) cout << i << " ";
        for(auto&it:common){
            if(r1<n/2 && m[it]>0 && mp[it]>0){
                 if(r1==n/2) break;
               r1++;
                m[it]--;
                if(m[it]==0) m.erase(it); 
            }
        }
     //      cout << r1 << " "<<r2 << "\n";
         if(r1==n/2 and r2==n/2) {long ans =an(m,mp); return ans; }
        
        
          for(auto&it:common){
            if(r2<n/2 && mp[it]>0 && m[it]>0){
                 if(r2==n/2) break;
               r2++;
                mp[it]--;
                if(mp[it]==0) mp.erase(it); 
            }
        }
     //      cout << r1 << " "<<r2 << "\n";
         if(r1==n/2 and r2==n/2) {long ans =an(m,mp); return ans; }
        
        //left 
        
        
        for(auto i : nums1){
            if(m[i]>1) {
                if(r1==n/2) break;
                r1++;
                m[i]--;
                if(m[i]==0) m.erase(i); 
            }
        }
        
         if(r1==n/2 and r2==n/2) {long ans =an(m,mp); return ans; }
        
        for(auto i : nums2){
            if(mp[i]>1) {
                 if(r2==n/2) break;
                r2++;
                mp[i]--;
                  if(mp[i]==0) mp.erase(i); 
            }
        }
        
        if(r1==n/2 and r2==n/2) {long ans = an(m,mp); return ans; }
        
        
        for(auto i : nums1){
            if(m[i]>0) {
                if(r1==n/2) break;
                r1++;
                m[i]--;
                if(m[i]==0) m.erase(i); 
            }
        }
      //     cout << r1 << " "<<r2 << "\n";
      //  if(r1==3 and r2==3)
       // for(auto i : m) cout << i.first << " "<<i.second << "\n";
    //    cout<<"\n";
      //   for(auto i : mp) cout << i.first << " "<<i.second << "\n";
         if(r1==n/2 and r2==n/2) {long ans = an(m,mp); return ans; }
        
        for(auto i : nums2){
            if(mp[i]>0) {
                 if(r2==n/2) break;
                r2++;
                mp[i]--;
                  if(mp[i]==0) mp.erase(i); 
            }
        }
           if(r1==n/2 and r2==n/2) {long ans = an(m,mp); return ans; }
          long ans = an(m,mp); return ans;
    }
};
