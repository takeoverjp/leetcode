/*
 * @lc app=leetcode id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
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
  int sumOfLeftLeaves(TreeNode* root) {
    if (!root) {
      return 0;
    }

    if (root->left) {
      if (!root->left->left && !root->left->right) {
        return root->left->val + sumOfLeftLeaves(root->right);
      }
    }
    return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
  }
};
// @lc code=end

// [1,2,3,4,null,null,5]
