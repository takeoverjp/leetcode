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
    return depth(root, 0) >= 0;
  }

 private:
  int depth(TreeNode* root, int currentDepth) {
    if (root == nullptr) {
      return currentDepth;
    }
    int leftDepth = depth(root->left, currentDepth + 1);
    if (leftDepth < 0) {
        return -1;
    }
    int rightDepth = depth(root->right, currentDepth + 1);
    if (rightDepth < 0) {
        return -1;
    }
    if (abs(leftDepth - rightDepth) > 1) {
        return -1;
    }
    return max(leftDepth, rightDepth);
  }
};
// @lc code=end
