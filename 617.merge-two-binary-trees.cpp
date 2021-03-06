/*
 * @lc app=leetcode id=617 lang=cpp
 *
 * [617] Merge Two Binary Trees
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) {
            return nullptr;
        }
        if (root1 && !root2) {
            return root1;
        }
        if (!root1 && root2) {
            return root2;
        }
        root1->left = mergeTrees(root1?root1->left:nullptr, root2?root2->left:nullptr);
        root1->right = mergeTrees(root1?root1->right:nullptr, root2?root2->right:nullptr);
        root1->val += root2->val;
        return root1;
    }
};
// @lc code=end

