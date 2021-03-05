/*
 * @lc app=leetcode id=606 lang=cpp
 *
 * [606] Construct String from Binary Tree
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
    string tree2str(TreeNode* t) {
        std::string ret;
        if (t == nullptr) {
            return ret;
        }
        ret += std::to_string(t->val);
        if (t->left) {
            ret += "(" + tree2str(t->left) + ")";
        }
        if (t->right) {
            if (!t->left) {
                ret += "()";
            }
            ret += "(" + tree2str(t->right) + ")";
        }
        return ret;
    }
};
// @lc code=end

