/*
 * @lc app=leetcode id=1022 lang=cpp
 *
 * [1022] Sum of Root To Leaf Binary Numbers
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

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
  int sumRootToLeaf(TreeNode *root) { return sumRootToLeaf(root, 0); }
  int sumRootToLeaf(TreeNode *root, int parent) {
    if (root == nullptr) {
      return parent;
    }
    if (!root->left && !root->right) {
      return 2 * parent + root->val;
    }
    return (root->left ? sumRootToLeaf(root->left, 2 * parent + root->val)
                       : 0) +
           (root->right ? sumRootToLeaf(root->right, 2 * parent + root->val)
                        : 0);
  }
};
// @lc code=end

int main() {
  Solution s;
  return 0;
}
