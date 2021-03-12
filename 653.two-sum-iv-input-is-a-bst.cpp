/*
 * @lc app=leetcode id=653 lang=cpp
 *
 * [653] Two Sum IV - Input is a BST
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
  bool findTarget(TreeNode* root, int k) {
    root_ = root;
    return findTargetRecurse(root, k);
  }

 private:
  bool findTargetRecurse(TreeNode* node, int k) {
    if (node == nullptr) {
      return false;
    }

    if (findNode(root_, k - node->val, node)) {
      return true;
    }
    if (findTargetRecurse(node->left, k)) {
      return true;
    }
    return findTargetRecurse(node->right, k);
  }

  bool findNode(TreeNode* node, int k, TreeNode* except) {
    if (node == nullptr) {
      return false;
    }
    if (node != except && node->val == k) {
      return true;
    }
    if (node->val > k) {
      return findNode(node->left, k, except);
    }
    return findNode(node->right, k, except);
  }
  TreeNode* root_;
};
// @lc code=end

// [1]\n2
// [0,-1,2,-3,null,null,4]\n-4
