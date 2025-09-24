#ifndef PALINDROMOS_H_INCLUDED
#define PALINDROMOS_H_INCLUDED
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

string manacherize(string s) {
    string newS = "^";

    for (char ch : s) {
        newS += "#" + string(1, ch);
    }

    newS += "#$";

    return newS;
}

pair<int, int> getIndicesPalindrome(const vector<int>& p) {
    int maxPos = 0;
    int maxSize = 0;

    for (int i = 0; i < p.size(); i++) {
        if (p[i] > maxSize) {
            maxSize = p[i];
            maxPos = i;
        }
    }
    //cout << "Max Pos: " << maxPos << endl;
    //cout << "Max Size: " << maxSize << endl;

    int l = (maxPos - (maxSize - 1)) / 2;
    int r = (maxPos + (maxSize - 1)) / 2;

    return {l, r};
}

pair<int, int> manachers(string s) {
    string S = manacherize(s);
    //cout << "Manacherized: " << S << endl;
    int n = S.length();

    int l = 0;
    int r = 0;

    vector<int> p(n, 0);

    for (int i = 1; i < n - 1; i++) {
        if (i < r) {
            int mirror = l + r - i;

            p[i] = min(r - i, p[mirror]);
        }

        while (S[i + p[i] + 1] == S[i - p[i] - 1]) {
            p[i]++;
        }

        if (i + p[i] > r) {
            l = i - p[i];
            r = i + p[i];
        }
    }

    //cout << "[";
    //for (int i = 0; i < p.size(); i++) {
    //    cout << p[i] << ",";
    //}
    //cout << "]" << endl;;

    pair<int, int> ps = getIndicesPalindrome(p);
    return ps;
}


pair<int, int> LPS(string s) {
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, 1));

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            if (i == j) {
                dp[i][j] = 1;
                continue;
            }

            if (s[i] == s[j]) {
                if (i + 1 == j) dp[i][j] = 2;
                else dp[i][j] = dp[i+1][j-1] + 2;
            }

            else {
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
    }

    int res = dp[0][n - 1];
    cout << "LPS: " << res << endl;

    return {0, 0};
}

#endif // PALINDROMOS_H_INCLUDED
