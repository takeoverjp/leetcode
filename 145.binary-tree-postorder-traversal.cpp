/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ret;
    postorderTraversal(root, ret);
    return ret;
  }

 private:
  void postorderTraversal(TreeNode* root, vector<int>& ret) {
    if (!root) {
      return;
    }
    postorderTraversal(root->left, ret);
    postorderTraversal(root->right, ret);
    ret.push_back(root->val);
  }
};
// @lc code=end
