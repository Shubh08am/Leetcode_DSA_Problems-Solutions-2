class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> m;
        for(int i = 0; i < s.size(); i++)
            m[s[i]]++;

        string ans = "";
        for(int i = 0; i < order.size(); i++)
        {
            if(!m.count(order[i]))
                continue;
            else while(m[order[i]] > 0)
            {
                ans.push_back(order[i]);
                m[order[i]]--;
            }
        }  
        for(int i = 0; i < s.size(); i++)
            while(m[s[i]] > 0)
            {
                ans.push_back(s[i]);
                m[s[i]]--;
            }

        return ans;
    }
};
