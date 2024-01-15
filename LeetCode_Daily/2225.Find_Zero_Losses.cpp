#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> m;
        for (int i = 0; i < matches.size(); i++) {
            m[matches[i][0]] += 0;
            m[matches[i][1]]++;
        }
        vector<vector<int>> ans(2);
        for (auto a : m) {
            if (a.second == 0) {
                ans[0].push_back(a.first);
            }
            if (a.second == 1) {
                ans[1].push_back(a.first);
            }
        }
        return ans;
    }
};
