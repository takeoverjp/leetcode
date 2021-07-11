/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> ancestor_p;
    vector<TreeNode*> ancestor_q;
    findNode(root, p, ancestor_p);
    findNode(root, q, ancestor_q);
    int size_p = ancestor_p.size();
    int size_q = ancestor_q.size();
    int size = std::min(size_p, size_q);
    int ret = 0;
    while (ret < size) {
    //   cout << "p = " << ancestor_p[size_p - ret - 1]->val << std::endl;
    //   cout << "q = " << ancestor_q[size_q - ret - 1]->val << std::endl;
      if (ancestor_p[size_p - ret - 1]->val !=
          ancestor_q[size_q - ret - 1]->val) {
        break;
      }
      ret++;
    }
    return ancestor_p[size_p - ret];
  }

 private:
  bool findNode(TreeNode* root, TreeNode* p, vector<TreeNode*>& ancestor) {
    if (!root) {
      return false;
    }
    if (root == p) {
      ancestor.push_back(root);
      return true;
    }
    bool ret = findNode(root->left, p, ancestor);
    if (ret) {
      ancestor.push_back(root);
      return ret;
    }
    ret = findNode(root->right, p, ancestor);
    if (ret) {
      ancestor.push_back(root);
    }
    return ret;
  }
};
// @lc code=end

//[6,2,8,0,4,7,9,null,null,3,5]\n2\n4