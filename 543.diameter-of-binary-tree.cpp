/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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
    int diameterOfBinaryTree(TreeNode* root) {
        max_dm_ = 0;
        maxDepth(root);
        return max_dm_;
    }
private:
    int max_dm_;
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int right = maxDepth(root->right);
        int left = maxDepth(root->left);
        max_dm_ = std::max(max_dm_, right + left);
        return std::max(right, left) + 1;
    }
};
// @lc code=end

