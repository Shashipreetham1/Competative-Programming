class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 1e9));
        for (int j = 0; j < m; j++) {
            dp[n - 1][j] = matrix[n - 1][j];
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                    dp[i][j] = min(dp[i][j], dp[i +1][j]+matrix[i][j]);
                    if (j - 1 >= 0)
                        dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]+matrix[i][j]);
                    if (j + 1 < m)
                        dp[i][j] = min(dp[i][j], dp[i + 1][j + 1]+matrix[i][j]);
            }
        }
        return *min_element(dp[0].begin(),dp[0].end());
    }
};