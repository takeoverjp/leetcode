/*
 * @lc app=leetcode id=872 lang=cpp
 *
 * [872] Leaf-Similar Trees
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
  bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> leaves1, leaves2;
    GetLeaves(root1, leaves1);
    GetLeaves(root2, leaves2);
    return leaves1 == leaves2;
  }

 private:
  void GetLeaves(TreeNode* root, vector<int>& leaves) {
    if (!root) {
      return;
    }
    if (isLeaf(root)) {
      leaves.push_back(root->val);
      return;
    }
    GetLeaves(root->left, leaves);
    GetLeaves(root->right, leaves);
  }
  bool isLeaf(TreeNode* root) { return root && !root->left && !root->right; }
};
// @lc code=end
