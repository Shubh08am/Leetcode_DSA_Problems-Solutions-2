class Solution {
public:
    int maxScore(string s) {
       int n = s.size(),split=0;
vector<int>z(n,0),o(n,0);
for(int i=0;i<n;i++){
	z[i]=(s[i]=='0');
	o[n-i-1]=(s[n-i-1]=='1');
}
for(int i=1;i<n-1;i++){
	z[i]+=z[i-1];
	o[n-1-i]+=o[n-i];
} 
for(auto i : o) cout << i << " ";
cout<<"\n";
for(auto i : z) cout << i << " ";
cout<<"\n";
//1 1 1 1
//0 0 0 0
//4 3 2 1 
for(int i=0;i<n-1;i++){
 split=max(split,z[i]+o[i+1]);	
}
return split; 
    }
};
