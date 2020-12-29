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
  void binaryTreePaths(vector<string>& ret, TreeNode* root, string t) {
    if (!(root->left || root->right)) {
      ret.push_back(t);
      return;
    }

    if (root->left) {
      binaryTreePaths(ret, root->left,
                      t + "->" + to_string(root->left->val));
    }
    if (root->right) {
      binaryTreePaths(ret, root->right,
                      t + "->" + to_string(root->right->val));
    }
  }
  vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> ret;
    if (root == nullptr) {
      return ret;
    }
    binaryTreePaths(ret, root, to_string(root->val));
    return ret;
  }
};
// @lc code=end
