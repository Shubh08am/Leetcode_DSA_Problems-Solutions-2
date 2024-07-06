class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n=colors.size(),alternating=0; 
        for(int i=0;i<n;i++){
            int first = colors[i%n] , second = colors[(i+1)%n] , third = colors[(i+2)%n] ; 
            if(first!=second && second!=third && first==third) alternating++;
        }
        return alternating;
    }
};
