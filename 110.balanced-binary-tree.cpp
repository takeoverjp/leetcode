/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
  bool isBalanced(TreeNode* root) {
    depth(root);
    return isBalancedInner(root);
  }

 private:
  bool isBalancedInner(TreeNode* root) {
    if (root == nullptr) {
      return true;
    }
    if (abs((root->left ? root->left->val : 0) -
            (root->right ? root->right->val : 0)) > 1) {
      return false;
    }
    return isBalanced(root->left) && isBalanced(root->right);
  }
  int depth(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }
    root->val = max(depth(root->left), depth(root->right)) + 1;
    return root->val;
  }
};
// @lc code=end
