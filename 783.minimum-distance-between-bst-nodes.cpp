/*
 * @lc app=leetcode id=783 lang=cpp
 *
 * [783] Minimum Distance Between BST Nodes
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

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
  int minDiffInBST(TreeNode* root) {
    min_ = INT_MAX;
    traverse(root);
    return min_;
  }

 private:
  void traverse(TreeNode* root) {
    if (root->left) {
      min_ = min(root->val - maxNode(root->left), min_);
      traverse(root->left);
    }
    if (root->right) {
      min_ = min(minNode(root->right) - root->val, min_);
      traverse(root->right);
    }
  }
  int maxNode(TreeNode* root) {
    if (root->right) {
      return maxNode(root->right);
    } else {
      return root->val;
    }
  }
  int minNode(TreeNode* root) {
    if (root->left) {
      return minNode(root->left);
    } else {
      return root->val;
    }
  }

 private:
  int min_;
};
// @lc code=end
