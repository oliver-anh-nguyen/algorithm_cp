

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<int> dp(text2.size() + 1, 0);
        for (int i = 0; i < text1.size(); i++) {
            int prev = 0;
            for (int j = 0; j < text2.size(); j++) {
                int cur = dp[j + 1];
                if (text1[i] == text2[j]) {
                    dp[j + 1] = 1 + prev;
                } else {
                    dp[j + 1] = max(cur, dp[j]);
                }
                prev = cur;
            }
        }
        return dp[text2.size()];
    }
};

