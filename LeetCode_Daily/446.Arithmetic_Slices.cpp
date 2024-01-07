//
//  main.cpp
//  2125.LaserBeams
//
//  Created by AnhNguyen on 02/01/2024.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int numberOfArithmeticSlices(std::vector<int>& nums) {
    int total = 0;
    int n = nums.size();
    std::vector<std::unordered_map<long, int>> dp(n);
    
    for (int i = 1; i < n; i++) {
        for ( int j = 0; j < i; j++) {
            long diff = (long)nums[j] - nums[i];
            dp[i][diff] += dp[j][diff] + 1;
            total += dp[j][diff];
        }
    }
    return total;
}

        
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> a{2,4,6,8,10};
    int ans = numberOfArithmeticSlices(a);
    cout << ans;
    return 0;
}
