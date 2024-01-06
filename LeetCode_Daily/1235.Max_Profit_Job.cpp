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

int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    vector<vector<int>> jobs;
    for (int i = 0; i < startTime.size(); i++) {
        jobs.push_back({endTime[i], startTime[i], profit[i]});
    }
    sort(jobs.begin(), jobs.end());
    map<int, int> dp = {{0, 0}};
    for (auto& j: jobs) {
        int cur = prev(dp.upper_bound(j[1]))->second + j[2];
        if (cur > dp.rbegin()->second) {
            dp[j[0]] = cur;
        }
    }
    return dp.rbegin()->second;
}

        
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> a{ 1,2,3,4,6 };
    vector<int> b{ 3,5,10,6,9};
    vector<int> c{ 20,20,100,70,60};
    
    int ans = jobScheduling(a, b, c);
    cout << ans;
    return 0;
}
