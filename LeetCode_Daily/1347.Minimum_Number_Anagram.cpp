#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> countS(26, 0);
        vector<int> countT(26, 0);
        for (char c : s) {
            countS[c - 'a']++;
        }
        for (char c : t) {
            countT[c - 'a']++;
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            ans += abs(countS[i] - countT[i]);
        }
        return ans / 2;
    }
};
