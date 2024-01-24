/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int pseudoPalindromicPaths(TreeNode* root) {
        return helper(root, 0);
    }

private:
    int helper(TreeNode* node, int path) {
        if (!node) {
            return 0;
        }
        path ^= (1 << node->val);

        if (!node->left && !node->right) {
            return (path & (path - 1)) == 0 ? 1 : 0;
        }
        return helper(node->left, path) + helper(node->right, path);
    }
};

