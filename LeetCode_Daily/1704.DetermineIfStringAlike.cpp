#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <queue>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int count = 0;
        int mid = s.length() / 2;
        for (int i = 0; i < mid; i++) {
            char a = s[i];
            char b = s[mid + i];
            if (vowels.count(a)) {
                count++;
            }
            if (vowels.count(b)) {
                count--;
            }
        }
        return count == 0;
    }
};
