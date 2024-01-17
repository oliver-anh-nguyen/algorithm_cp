#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> dict;
        for (int i : arr) {
            dict[i]++;
        }
        vector<int> occurs;
        for (auto& item: dict) {
            if (find(occurs.begin(), occurs.end(), item.second) != occurs.end()) {
                return false;
            }
            occurs.push_back(item.second);
        }
        return true;
    }
};
