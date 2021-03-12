/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
  bool isSymmetric(TreeNode* root) {
    if (root == nullptr) {
      return true;
    }

    return isSymmetric(root->left, root->right);
  }

 private:
  bool isSymmetric(TreeNode* left, TreeNode* right) {
    if (!left && !right) {
      return true;
    }
    if ((!left && right) || (left && !right)) {
      return false;
    }
    if (left->val != right->val) {
      return false;
    }
    return isSymmetric(left->left, right->right) &&
           isSymmetric(left->right, right->left);
  }
};
// @lc code=end
