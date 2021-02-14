/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
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
  int getMinimumDifference(TreeNode* root) {
    int ret = INT_MAX;
    if (!root) {
      return ret;
    }
    if (root->right) {
      TreeNode* rightMin = root->right;
      while (rightMin->left) {
        rightMin = rightMin->left;
      }
      ret = std::min(ret, std::abs(rightMin->val - root->val));
      ret = std::min(ret, getMinimumDifference(root->right));
    }
    if (root->left) {
      TreeNode* leftMax = root->left;
      while (leftMax->right) {
        leftMax = leftMax->right;
      }
      ret = std::min(ret, std::abs(leftMax->val - root->val));
      ret = std::min(ret, getMinimumDifference(root->left));
    }
    return ret;
  }
};
// @lc code=end

// [236,104,701,null,227,null,911] = 9