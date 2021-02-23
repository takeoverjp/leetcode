/*
 * @lc app=leetcode id=563 lang=cpp
 *
 * [563] Binary Tree Tilt
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
    int findTilt(TreeNode* root) {
        int sum = 0;
        return traverse(root, sum);
    }

    int traverse(TreeNode* root, int& sum) {
        if (root == nullptr) {
            return 0;
        }
        int tilt = 0;
        int left_sum = 0;
        int right_sum = 0;
        tilt += traverse(root->left, left_sum);
        tilt += traverse(root->right, right_sum);
        tilt += std::abs(left_sum - right_sum);
        sum += root->val;
        sum += left_sum;
        sum += right_sum;
        return tilt;
    }
};
// @lc code=end

