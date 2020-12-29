/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 */

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
  vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> ret;
    if (root == nullptr) {
      return ret;
    }

    if (!(root->left || root->right)) {
        ret.push_back(to_string(root->val));
        return ret;
    }

    for (const string& path : binaryTreePaths(root->left)) {
      ret.push_back(to_string(root->val) + "->" + path);
    }
    for (const string& path : binaryTreePaths(root->right)) {
      ret.push_back(to_string(root->val) + "->" + path);
    }
    return ret;
  }
};
// @lc code=end
