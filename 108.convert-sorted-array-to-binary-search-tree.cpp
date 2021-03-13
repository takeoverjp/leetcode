/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return sortedArrayToBST(nums, 0, nums.size() - 1);
  }

 private:
  TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end) {
    //  cout << start << "," << end << endl;
    if (start > end) {
      return nullptr;
    }
    if (start == end) {
      return new TreeNode(nums[start]);
    }
    int mid = (start + end) / 2;
    TreeNode* left = sortedArrayToBST(nums, start, mid - 1);
    TreeNode* right = sortedArrayToBST(nums, mid + 1, end);
    return new TreeNode(nums[mid], left, right);
  }
};
// @lc code=end
