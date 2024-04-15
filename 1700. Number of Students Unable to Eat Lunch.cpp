class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n=students.size();
        int res=n;
        vector<int>cnt(n+1);
        for(int i=0;i<n;i++)
        {
            cnt[students[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(cnt[sandwiches[i]]>0)
            {
                cnt[sandwiches[i]]--;
                res--;
            }else{
                return res;
            }
        }
        return res;
    }
};
