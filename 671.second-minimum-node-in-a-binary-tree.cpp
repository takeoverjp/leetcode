/*
 * @lc app=leetcode id=671 lang=cpp
 *
 * [671] Second Minimum Node In a Binary Tree
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
  int findSecondMinimumValue(TreeNode* root) {
    minimum_ = root->val;
    second_ = __INT64_MAX__;

    traverse(root);

    return second_ == __INT64_MAX__ ? -1 : second_;
  }

 private:
  int minimum_;
  int64_t second_;
  void traverse(TreeNode* root) {
    if (!root) {
      return;
    }
    if (root->val != minimum_) {
        second_ = min(second_, static_cast<int64_t>(root->val));
    }
    traverse(root->left);
    traverse(root->right);
  }
};
// @lc code=end

// [1,1,3,1,1,3,4,3,1,1,1,3,8,4,8,3,3,1,6,2,1]
// [2,2,2147483647]