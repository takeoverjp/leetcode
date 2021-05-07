/*
 * @lc app=leetcode id=876 lang=cpp
 *
 * [876] Middle of the Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  ListNode* middleNode(ListNode* head) {
    auto node = head;
    auto ret = head;
    int count = 0;
    while (node) {
      node = node->next;
      if ((++count) % 2 == 0) {
        ret = ret->next;
      }
    }
    return ret;
  }
};
// @lc code=end
