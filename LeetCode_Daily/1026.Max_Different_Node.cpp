//
//  main.cpp
//  2125.LaserBeams
//
//  Created by AnhNguyen on 02/01/2024.
//

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
    int ans;
    void solve(TreeNode* root, int maxVal, int minVal) {
        if (!root) {
            ans = max(ans, abs(maxVal - minVal));
            return;
        }
        maxVal = max(maxVal, root->val);
        minVal = min(minVal, root->val);
        solve(root->left, maxVal, minVal);
        solve(root->right, maxVal, minVal);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        if (!root) {
            return 0;
        }
        ans = 0;
        solve(root, root->val, root->val);
        return ans;
    }
};

