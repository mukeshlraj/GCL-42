#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> memo;

// TC : O(m * n)
// Aux Space : O(m * n)

// This function will return LCS of s1[i...n-1] and s2[j....m-1]
int lcs_helper(string &s1, int i, string &s2, int j) {

    // Base Cases
    if (i==s1.length() || j==s2.length()) {
        return 0;
    }

    // Result of current state has been evaluated
    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    // Store the result and return
    if(s1[i] == s2[j]) {
        return memo[i][j] = 1 + lcs_helper(s1, i+1, s2, j+1);
    }

    return max(lcs_helper(s1, i, s2, j+1), lcs_helper(s1, i+1, s2, j));
}

int lcs(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();

    memo = vector<vector<int>> (n, vector<int> (m, -1));

    return lcs_helper(s1, 0, s2, 0);
}

int lcs_bottom_up(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n+1, vector<int> (m+1));

    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 0;
    }

    for (int j = 0; j <= m; ++j) {
        dp[0][j] = 0;
    }

    for (int i = 1; i <=n ; ++i) {
        for (int j = 1; j <=m ; ++j) {
            if(s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }

    return dp[n][m];
}

int main() {
    cout << lcs("ABCDGH","AEDFHR") << endl;
    cout << lcs("ABC", "AC") << endl;

    cout << lcs_bottom_up("ABCDGH","AEDFHR") << endl;
    cout << lcs_bottom_up("ABC", "AC") << endl;
}