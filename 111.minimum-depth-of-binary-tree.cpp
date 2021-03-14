/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
  int minDepth(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }
    if (root->left == nullptr && root->right == nullptr) {
      return 1;
    }
    if (root->left == nullptr) {
      return minDepth(root->right) + 1;
    }
    if (root->right == nullptr) {
      return minDepth(root->left) + 1;
    }
    return min(minDepth(root->left), minDepth(root->right)) + 1;
  }
};
// @lc code=end

// [2,null,3,null,4,null,5,null,6]
// 5 