class Solution {
public:
    int minOperations(string s) {
       int a=0,b=0,c=0,d=0,n=s.size();

for(int i=0;i<n;i+=2){
	if(s[i]!='1') a++;
}
for(int i=1;i<n;i+=2){
	if(s[i]!='0') b++;
}
for(int i=0;i<n;i+=2){
	if(s[i]!='0') c++;
}
for(int i=1;i<n;i+=2){
	if(s[i]!='1') d++;
}
return min(a+b,c+d); 
    }
};
