class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        sort(tokens.begin(),tokens.end());

        if(n == 0 || power < tokens[0]) return 0;

        int maxScore = 0 , curScore = 0;
        int start = 0 , end = n-1;

        while(start <= end){
            while(start <= end && power >= tokens[start]){
                power -= tokens[start];
                curScore++;
                start++;
            }
            maxScore = max(maxScore,curScore);
            while(start <= end && power < tokens[start]){
                power += tokens[end];
                curScore--;
                end--;
            }
        }
        maxScore = max(maxScore,curScore);
        return maxScore;
    }
};
