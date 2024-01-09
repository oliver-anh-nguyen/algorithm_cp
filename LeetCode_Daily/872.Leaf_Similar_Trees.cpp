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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> arr1, arr2;
        getLeafs(root1, arr1);
        getLeafs(root2, arr2);
        return arr1 == arr2;
    }

    void getLeafs(TreeNode* node, vector<int>& arr) {
        if (!node) {
            return;
        }
        if (!node->left && !node->right) {
            arr.push_back(node->val);
            return;
        }
        getLeafs(node->left, arr);
        getLeafs(node->right, arr);
    }
};
