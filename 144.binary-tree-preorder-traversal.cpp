/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  vector<int> preorderTraversal(TreeNode* root) {
    stack<TreeNode*> node_stack;
    TreeNode* curr = root;
    vector<int> ret;
    while ((curr != nullptr) || node_stack.size()) {
      if (curr) {
        ret.push_back(curr->val);
        node_stack.push(curr);
        curr = curr->left;
      } else {
        curr = node_stack.top();
        node_stack.pop();
        curr = curr->right;
      }
    }
    return ret;
  }
};

// @lc code=end
