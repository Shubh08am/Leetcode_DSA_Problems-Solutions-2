class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n=rating.size(),teams=0; 
        for(int i=1;i<n-1;i++){
            int second=rating[i];
            vector<int>left,right; 
            for(int l=0;l<i;l++) left.push_back(rating[l]); 
            for(int r=i+1;r<n;r++) right.push_back(rating[r]); 
            sort(left.begin(),left.end()); 
            sort(right.begin(),right.end()); 
            int pos_l=i-1,pos_r=0; 
            while(pos_l>=0 && left[pos_l]>=second) pos_l--; 
            while(pos_r<right.size() && right[pos_r]<=second) pos_r++; 
            teams+=((pos_l+1)*(right.size()-pos_r)); 
     //       cout<<i<<" "<<teams<<"\n";
          
            reverse(left.begin(),left.end()); 
            reverse(right.begin(),right.end()); 
            int pos_l2=i-1,pos_r2=0; 
            while(pos_l2>=0 && left[pos_l2]<=second) pos_l2--; 
            while(pos_r2<right.size() && right[pos_r2]>=second) pos_r2++;
            teams+=((pos_l2+1)*(right.size()-pos_r2)); 
     //        cout<<i<<" "<<teams<<"\n";
        }
        return teams;
    }
};
