/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
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
  bool isSubtree(TreeNode* s, TreeNode* t) {
    if (t == nullptr) {
      return true;
    }
    if (s == nullptr) {
      return false;
    }
    if (isSametree(s, t)) {
      return true;
    }
    if (isSubtree(s->left, t)) {
      return true;
    }
    if (isSubtree(s->right, t)) {
      return true;
    }
    return false;
  }

 private:
  bool isSametree(TreeNode* s, TreeNode* t) {
    if (s == nullptr && t == nullptr) {
      return true;
    }
    if (s == nullptr || t == nullptr) {
      return false;
    }
    if ((s->val == t->val) && (isSametree(s->left, t->left)) &&
        (isSametree(s->right, t->right))) {
      return true;
    }
    return false;
  }
};
// @lc code=end
