#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }

        vector<vector<bool>> dp(s1.length() + 1, vector<bool>(s2.length() + 1, false));
        dp[s1.length()][s2.length()] = true;

        for (int i = s1.length(); i >= 0; i--) {
            for (int j = s2.length(); j >= 0; j--) {
                if (i < s1.length() && s1[i] == s3[i + j] && dp[i + 1][j]) {
                    dp[i][j] = true;
                }
                if (j < s2.length() && s2[j] == s3[i + j] && dp[i][j + 1]) {
                    dp[i][j] = true;
                }
            }
        }
        return dp[0][0];
    }

private:
    struct PairHash {
        template <class T1, class T2>
        size_t operator() (const pair<T1, T2>& p) const {
            auto h1 = hash<T1>{}(p.first);
            auto h2 = hash<T2>{}(p.second);
            return h1 ^ (h2 << 1);
        }
    };
    
    unordered_map<pair<int, int>, bool, PairHash> dp;
    bool dfs(int i, int j, string& s1, string& s2, string& s3) {
        if (i == s1.length() && j == s2.length()) {
            return true;
        }
        if (dp.find({i, j}) != dp.end()) {
            return dp[{i, j}];
        }

        bool result = false;
        if (i < s1.length() && s1[i] == s3[i + j] && dfs(i + 1, j, s1, s2, s3)) {
            result = true;
        }
        if (j < s2.length() && s2[j] == s3[i + j] && dfs(i, j + 1, s1, s2, s3)) {
            result = true;
        }

        dp[{i, j}] = result;
        return result;
    }
};
