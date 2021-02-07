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
        vector<int> ret;
        traverse(root, ret);
        return ret;
    }
    private:
    int pre_cursor_ = INT_MIN;
    int count_ = 0;
    int max_count_ = 0;
    void traverse(TreeNode* root, vector<int>& ret) {
        if (root == nullptr) return;

        traverse(root->left, ret);

        if (root->val == pre_cursor_) {
            count_++;
        } else {
            count_ = 1;
        }

        if (count_ > max_count_) {
            ret.clear();
            max_count_ = count_;
            ret.push_back(root->val);
        } else if (count_ == max_count_){
            ret.push_back(root->val);
        }

        pre_cursor_ = root->val;

        traverse(root->right, ret);
    }
};
// @lc code=end

// [2147483647]