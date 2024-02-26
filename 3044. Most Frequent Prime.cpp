class Solution {
public:
    bool p(int n) {
        if (n < 2) {
            return 0;
        }
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    bool ok(long long x, long long y, int n, int m) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    int mostFrequentPrime(vector<vector<int>>& mat) {
        vector<pair<int,int>> dirs = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
        map<long long, long long> mp;
        int n = mat.size(), m = mat[0].size();
        long long maxi = 0, prime = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (auto& it : dirs) {
                    long long res = 0;
                    long long curr_x = i, curr_y = j;
                    while (ok(curr_x, curr_y, n, m)) {
                        res = 1ll * res * 10 + (mat[curr_x][curr_y]);
                        if (res >= 11 && p(res))  mp[res]++;
                        curr_x += it.first;
                        curr_y += it.second;
                    }
                }
            }
        }
        for (auto& it : mp) {
            if (it.second > maxi) {
                maxi = it.second;
                prime = it.first;
            }
            else if (it.second == maxi && it.first > prime) {
                prime = it.first;
            }
        }
        return prime; 
    }
};
