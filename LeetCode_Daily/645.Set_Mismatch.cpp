#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> numSet;
        int dup = 0, miss = 0;
        for (int n : nums) {
            if (numSet.count(n)) {
                dup = n;
            } else {
                numSet.insert(n);
            }
        }
        
        for (int i = 1; i <= nums.size(); i++) {
            if (numSet.count(i) == 0) {
                miss = i;
                break;
            }
        }
        return {dup, miss};
    }
};


