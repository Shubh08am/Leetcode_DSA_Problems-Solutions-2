class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        string ans;
        int n=s.size();
        for (int i = 0; i < n; i ++) {
            if (s[i] == '(') {
                st.push(i);    
            } 
            else if (s[i] == ')') {
                int pos = st.top();
                st.pop();
                reverse(s.begin() + pos + 1, s.begin() + i);
            }
        }
        for (auto it: s) {
            if (it != '(' && it != ')') {
                ans+=it;
            }
        }
        return ans;
    }
};
