/*
 * @lc app=leetcode id=637 lang=cpp
 *
 * [637] Average of Levels in Binary Tree
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ret;
        if (!root) {
            return ret;
        }
        int depth = 0;
        accums.push_back({1, root->val});
        traverse(depth+1, root->left);
        traverse(depth+1, root->right);
        for (const auto& accum : accums) {
            ret.push_back(static_cast<double>(accum.sum) / accum.count);
        }
        return ret;
    }
    private:
    typedef struct _accum_t {
        int count;
        quad_t sum;
    } accum_t;
    vector<accum_t> accums;

    void traverse(int depth, TreeNode* root) {
        if (!root) {
            return;
        }
        if (accums.size() <= depth) {
            accums.push_back({1, root->val});
        } else {
            accums[depth].count++;
            accums[depth].sum += root->val;
        }
        traverse(depth+1, root->left);
        traverse(depth+1, root->right);
    }
};
// @lc code=end

