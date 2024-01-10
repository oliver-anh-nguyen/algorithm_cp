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
    unordered_map<int, vector<int>> graph;
    int amountOfTime(TreeNode* root, int start) {
        convertToGraph(root);
        int ans = 0;
        queue<int> q;
        q.push(start);
        
        unordered_set<int> visited;
        while(!q.empty()) {
            ans += 1;
            for (unsigned long s = q.size(); s > 0; s--) {
                int cur = q.front();
                q.pop();
                visited.insert(cur);
                for (int v : graph[cur]) {
                    if (!visited.count(v)) {
                        q.push(v);
                    }
                }
            }
        }
        return ans;
    }
    
    void convertToGraph(TreeNode* node) {
        if (!node) {
            return;
        }
        if (node->left) {
            graph[node->val].push_back(node->left->val);
            graph[node->left->val].push_back(node->val);
        }
        if (node->right) {
            graph[node->val].push_back(node->right->val);
            graph[node->right->val].push_back(node->val);
        }
        convertToGraph(node->left);
        convertToGraph(node->right);
    }
};

