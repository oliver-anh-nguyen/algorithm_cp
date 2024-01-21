#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int dp = 0;
        int dp1 = 0;
        int dp2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            dp = max(dp1, dp2 + nums[i]);
            dp2 = dp1;
            dp1 = dp;
        }
        return dp1;
    }
};
