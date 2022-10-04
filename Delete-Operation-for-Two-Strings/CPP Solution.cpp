#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        // Bottom up approach
        int m, n;
        m = word1.length();
        n = word2.length();
        int dp[m + 1][n + 1];

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                // we have to add all the remaining char in word2
                if (i == 0)
                    dp[i][j] = j; 
                // We have to delete all the remaining characters from word 1
                else if (j == 0)
                    dp[i][j] = i; 
                // If in the memo dict return the val
                else if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];

                else
                    dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j]);
            }
        }

        return dp[m][n];
    }
};