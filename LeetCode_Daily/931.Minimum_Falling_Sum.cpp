#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp = matrix;
        for (int r = 1; r < n; r++) {
            for (int c = 0; c < n; c++) {
                dp[r][c] += min({
                    dp[r-1][c],
                    (c > 0) ? dp[r-1][c-1] : INT_MAX,
                    (c < n-1) ? dp[r-1][c+1] : INT_MAX
                });
            }
        }
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};
