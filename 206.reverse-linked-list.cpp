/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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
  ListNode* reverseList(ListNode* head) {
    if (!head || !(head->next)) {
      return head;
    }
    ListNode* ret = nullptr;
    ListNode* node = head;
    ListNode* next = head->next;
    while (node) {
      next = node->next;
      node->next = ret;
      ret = node;
      node = next;
    }
    return ret;
  }

  ListNode* reverseListRecursive(ListNode* head) {
    if (head == nullptr) {
      return nullptr;
    }
    if (head->next == nullptr) {
      return head;
    }
    ListNode* tail = head->next;
    ListNode* ret = reverseList(head->next);
    tail->next = head;
    head->next = nullptr;
    return ret;
  }
};
// @lc code=end
