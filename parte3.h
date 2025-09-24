#include <vector>
#include <string>
#include <utility>

using namespace std;

pair<int, int> longestCommonSubstring(const string& s1, const string& s2) {
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    int maxLen = 0;
    int endPos = -1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLen) {
                    maxLen = dp[i][j];
                    endPos = i;
                }
            }
        }
    }
    if (maxLen == 0) {
        return {0, 0}; // or handle as needed
    }
    int startPos = endPos - maxLen + 1;
    return {startPos, endPos};
}

// con ayuda de https://www.geeksforgeeks.org/dsa/longest-common-substring-dp-29/