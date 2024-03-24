/*
"n is odd use ->" 
finding first number

a1,(a2,a3),(a4,a5).....,
making the decoded into pairs.
a2^a3 = A[1]
a4^a5 = A[3]
a6^a7 = A[5]

so we can have the result of a2^a3^a4...^an.
And a1,a2,a3... is a permuatation of 1,2,3,4..n

so we can have
a1 = 1^2^3...^n^a2^a2^a3...^an

Then we can deduct the whole decoded array.
*/

class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size(),num=0; 
        vector<int>perm(n+1) ; 
        for(int i=1;i<=n+1;i++) num^=i; 
        for(int i=1;i<n;i+=2) num^=encoded[i];
        perm[0]=num;
        for(int i=1;i<=n;i++){
            perm[i] = (perm[i-1]^encoded[i-1]);
        }
    return perm;
    }
};
