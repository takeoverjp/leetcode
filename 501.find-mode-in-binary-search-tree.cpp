/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
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
    vector<int> findMode(TreeNode* root) {
        map<int, int> counts;
        countNode(root, counts);
        int max = 0;
        for (const auto& it : counts) {
            if (it.second >= max) {
                max = it.second;
            }
        }
        vector<int> ret;
        if (max == 0) {
            return ret;
        }
        for (const auto& it : counts) {
            if (it.second == max) {
                ret.push_back(it.first);
            }
        }
        return ret;
    }
    private:
    void countNode(TreeNode* root, map<int, int>& counts) {
        if (root == nullptr) return;
        counts[root->val]++;
        countNode(root->left, counts);
        countNode(root->right, counts);
    }
};
// @lc code=end

// [2147483647]