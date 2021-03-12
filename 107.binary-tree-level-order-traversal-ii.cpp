/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
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
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> ret;
    traverse(root, 0, ret);
    reverse(ret.begin(), ret.end());
    return ret;
  }

 private:
  void traverse(TreeNode* root, int depth, vector<vector<int>>& ret) {
    if (!root) {
      return;
    }
    if (ret.size() <= depth) {
      ret.push_back({});
    }
    ret[depth].push_back(root->val);
    traverse(root->left, depth + 1, ret);
    traverse(root->right, depth + 1, ret);
  }
};
// @lc code=end
